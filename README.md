Elastos Carrier Android SDK
===========================

[![Build Status](https://travis-ci.org/elastos/Elastos.NET.Carrier.Android.SDK.svg)](https://travis-ci.org/elastos/Elastos.NET.Carrier.Android.SDK)

## Summary

Elastos Carrier Android SDK is a Java API wrapper for the C language based [Elastos Carrier Native SDK](https://github.com/elastos/Elastos.NET.Carrier.Native.SDK). With the Android Carrier SDK, it is possible to build applications for mobile phones, tablets, wearables, TVs and car media systems that run on the Android Operating System (OS) while utilizing the functionalities of the Elastos Carrier.

The Elastos Carrier is a decentralized and encrypted peer-to-peer (P2P) communication framework that routes network traffic between virtual machines and Decentralized Applications (DApps).

The authentication process of peer nodes utilizes the Elastos Decentralized ID (DID) sidechain. （TODO）

## Build from source

### 1. Cross-compilation for Android Platform on Ubuntu / Debian / Linux or MacOS host

***************

With CMake, Elastos Carrier can be cross-compiled to run on Android as a target platform, while compilation is carried out on a(n) Ubuntu / Debian / Linux or MacOS host.

**Prerequisite**: Android NDK 'android-ndk-r16b' or higher must be downloaded onto the host.
Android NDKs (such as 'Linux 64-bit (x86)' or 'Mac' ) can be downloaded from https://developer.android.com/ndk/downloads/ .
Please make sure to extract the downloaded NDK.

Open a new terminal window.

Download the **Elastos.NET.Carrier.Native.SDK** (not the Elastos.NET.Carrier.Android.SDK) repository using Git:
```shell
$ git clone https://github.com/elastos/Elastos.NET.Carrier.Native.SDK
```

Navigate to the previously downloaded folder that contains the source code of the Carrier project.

```shell
$ cd YOUR-PATH/Elastos.NET.Carrier.Native.SDK
```

Enter the 'build' folder.
```shell
$ cd build
```

Create a new folder with the target platform name, then change directory.
```shell
$ mkdir android
$ cd android
```

To generate the required Makefile in the current directory, please make sure to first replace 'YOUR-TARGET-ARCHITECTURE'
and 'YOUR-ANDROID-NDK-HOME' with the correct option and path.

-DANDROID_ABI accepts the following target architecture options:
* armeabi-v7a
* arm64-v8a
* x86
* x86_64

Replace 'YOUR-ANDROID-NDK-HOME' with the path to the extracted NDK folder.

Run the command with the correct options described above:
```shell
$ cmake -DANDROID_ABI=YOUR-TARGET-ARCHITECTURE -DANDROID_NDK_HOME=YOUR-ANDROID-NDK-HOME -DCMAKE_TOOLCHAIN_FILE=../../cmake/AndroidToolchain.cmake ../..

```

Build the program: <br/>
Note: If "make" fails due to missing permissions, use "sudo make" instead.
```shell
$ make
```



Install the program: <br/>
Note: If "make install" fails due to missing permissions, use "sudo make install" instead.
```shell
$ make install
```


Create distribution package: <br/>
Note: If "make dist" fails due to missing permissions, use "sudo make dist" instead.
```
$ make dist
```

Note: To build for multiple target architectures separately, repeat the steps starting from:

Run the command with the correct options described above:
```shell
$ cmake -DANDROID_ABI=YOUR-TARGET-ARCHITECTURE -DANDROID_NDK_HOME=YOUR-ANDROID-NDK-HOME -DCMAKE_TOOLCHAIN_FILE=../../cmake/AndroidToolchain.cmake ../..

```

For each architecture, the distribution package will contain the following files:
```
libcrystal.so
libelacarrier.so
libelasession.so
```

These shared native libraries will have to be later imported into the Android project based on their
target architectures.

Currently, the CPU architectures **armv7l**, **arm64**, **x86**, **x86-64** are supported.


### 2.Import Shared Native Libraries

The directory **"app/native-dist"** to import native libraries and headers should have following directory structure:

```
app/native-dist
   |--include
       |--ela_carrier.h
       |--ela_session.h
   |--libs
       |--armeabi-v7a
          |--libcrystal.so
          |--libelacarrier.so
          |--libelasession.so
       |--arm64-v8a
          |--libcrystal.so
          |--libelacarrier.so
          |--libelasession.so
       |--x86
          |--libcrystal.so
          |--libelacarrier.so
          |--libelasession.so
       |--x86-64
          |--libcrystal.so
          |--libelacarrier.so
          |--libelasession.so
```

The headers under subdirectory **"include"** are public header files exported from Carrier native. And shared libraries under **libs** to each CPU arch are built from Carrier native.

### 3. Build Carrier SDK

After importing dependencies from Carrier native, you need Android Studio to open this project and build Carrier Android SDK.

### 4. Output

After building with success, the output dist named **org.elastos.carrier-debug(release).aar** carrying jar package and JNI shared libraries to different CPU arch would be put under the directory:

```
app/build/outputs/aar
```

## Basic Tests

All basic tests are located under directory **"app/src/androidTest"**. You can run the tests on Android Studio. Before running tests, you need to uncomment **"service"** configuration in AndroidMinifest.xml.

## Build Docs

Open **Tools** tab on Android Studio and click **Generate JavaDoc...** item to generate the Java API document.

## Thanks

Sincerely thanks to all teams and projects that we relies on directly or indirectly.

## Contributing

We welcome contributions to the Elastos Carrier Android Project (or Native Project) in many forms.

## License

Elastos Carrier Android Project source code files are made available under the MIT License, located in the LICENSE file.
