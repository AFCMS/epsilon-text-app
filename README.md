# Text App for Epsilon

[![Build](https://github.com/AFCMS/epsilon-text-app/actions/workflows/build.yml/badge.svg)](https://github.com/AFCMS/epsilon-text-app/actions/workflows/build.yml)

This is a C++ app to display text on a [NumWorks calculator](https://www.numworks.com).

The code is derivated from the [official numworks sample app](https://github.com/numworks/epsilon-sample-app-cpp);

## Build the app

To build this sample app, you will need to install the [embedded ARM toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) and [nwlink](https://www.npmjs.com/package/nwlink).

```shell
brew install numworks/tap/arm-none-eabi-gcc node # Or equivalent on your OS
npm install -g nwlink
make
```

You should now have a `target/voord.nwa` file that you can distribute! Anyone can now install it on their calculator from the [NumWorks online uploader](https://my.numworks.com/apps).

## Run the app locally

To run the app on your development machine, you can use the following command

```shell
# Now connect your NumWorks calculator to your computer using the USB cable
make run
```

## Copyright

AFCM:
src/main.cpp

Numworks team (BSD):
All other files
