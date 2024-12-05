# dkls-android
This reporitory contains the source code to build DKLS/Schnorr libraries for android

## How to build
1. you need to use the build script in dkls repository to build the libs first, usually it spit out libgodkls.so and libgoschnorr.so, for all the platforms you want to support.
2. copy the libs to dkls/src/main/cpp/libs folder or goschnorr/src/main/cpp/libs folder
3. run the following command to build the aar file
```
./gradlew clean bundleReleaseAar
```
4. the aar file will be in dkls/build/outputs/aar or goschnorr/build/outputs/aar folder