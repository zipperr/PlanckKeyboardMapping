# PlanckKeyboardMapping
Plank Rev6 KeyMapping

brew tap osx-cross/avr
brew tap PX4/homebrew-px4
brew update
brew install avr-gcc
brew install dfu-programmer
brew install gcc-arm-none-eabi
brew install dfu-util
make planck/rev6:zipper:dfu-util
