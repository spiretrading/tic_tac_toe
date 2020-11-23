@ECHO OFF
SETLOCAL EnableDelayedExpansion
SET EXIT_STATUS=0
SET ROOT=%cd%
IF EXIST cache_files\tic_tac_toe.txt (
  FOR /F %%i IN (
      'ls -l --time-style=full-iso "%~dp0\setup.bat" ^| awk "{print $6 $7}"') DO (
    FOR /F %%j IN (
        'ls -l --time-style=full-iso cache_files\tic_tac_toe.txt ^| awk "{print $6 $7}"') DO (
      IF "%%i" LSS "%%j" (
        EXIT /B 0
      )
    )
  )
)
SET VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
FOR /f "usebackq delims=" %%i IN (`!VSWHERE! -prerelease -latest -property installationPath`) DO (
  IF EXIST "%%i\Common7\Tools\vsdevcmd.bat" (
    CALL "%%i\Common7\Tools\vsdevcmd.bat"
  )
)
IF NOT EXIST Strawberry (
  wget http://strawberryperl.com/download/5.30.1.1/strawberry-perl-5.30.1.1-64bit-portable.zip -O strawberry-perl-5.30.1.1-64bit-portable.zip --no-check-certificate
  IF !ERRORLEVEL! LEQ 0 (
    MD Strawberry
    PUSHD Strawberry
    unzip ..\strawberry-perl-5.30.1.1-64bit-portable.zip
    POPD
  ) ELSE (
    SET EXIT_STATUS=1
  )
  DEL /F /Q strawberry-perl-5.30.1.1-64bit-portable.zip
)
SET PATH=!PATH!;!ROOT!\Strawberry\perl\site\bin;!ROOT!\Strawberry\perl\bin;!ROOT!\Strawberry\c\bin
IF NOT EXIST doctest-2.3.6 (
  wget https://github.com/onqtam/doctest/archive/2.3.6.zip --no-check-certificate
  IF !ERRORLEVEL! LEQ 0 (
    unzip 2.3.6.zip
  ) ELSE (
    SET EXIT_STATUS=1
  )
  DEL /F /Q 2.3.6.zip
)
IF NOT EXIST qt-5.14.0 (
  git clone git://code.qt.io/qt/qt5.git qt-5.14.0
  IF !ERRORLEVEL! EQU 0 (
    PUSHD qt-5.14.0
    git checkout 5.14.0
    perl init-repository --module-subset=default
    CALL configure -prefix %cd% -opensource -static -mp -make libs -make tools ^
      -nomake examples -nomake tests -opengl desktop -no-icu -qt-freetype ^
      -qt-harfbuzz -qt-libpng -qt-pcre -qt-zlib -confirm-license
    SET CL=/MP
    nmake
    DEL qtbase\lib\cmake\Qt5Core\Qt5CoreConfigExtrasMkspecDir.cmake
    COPY NUL qtbase\lib\cmake\Qt5Core\Qt5CoreConfigExtrasMkspecDir.cmake
    POPD
  ) ELSE (
    RD /S /Q qt-5.14.0
    SET EXIT_STATUS=1
  )
)
IF "%NUMBER_OF_PROCESSORS%" == "" (
  SET BJAM_PROCESSORS=
) ELSE (
  SET BJAM_PROCESSORS="-j%NUMBER_OF_PROCESSORS%"
)
IF NOT EXIST boost_1_72_0 (
  wget https://dl.bintray.com/boostorg/release/1.72.0/source/boost_1_72_0.zip -O boost_1_72_0.zip --no-check-certificate
  IF !ERRORLEVEL! LEQ 0 (
    unzip boost_1_72_0.zip
    PUSHD boost_1_72_0
    PUSHD tools\build
    CALL bootstrap.bat vc142
    POPD
    tools\build\b2 !BJAM_PROCESSORS! --without-context --prefix="!ROOT!\boost_1_72_0" --build-type=complete address-model=32 toolset=msvc-14.2 link=static,shared runtime-link=shared install
    tools\build\b2 !BJAM_PROCESSORS! --with-context --prefix="!ROOT!\boost_1_72_0" --build-type=complete address-model=32 toolset=msvc-14.2 link=static runtime-link=shared install
    POPD
  ) ELSE (
    SET EXIT_STATUS=1
  )
  DEL /F /Q boost_1_72_0.zip
)
IF NOT EXIST cache_files (
  MD cache_files
)
ECHO timestamp > cache_files\tic_tac_toe.txt
ENDLOCAL
EXIT /B !EXIT_STATUS!
