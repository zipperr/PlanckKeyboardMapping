# PlanckKeyboardMapping
Plank Rev6 KeyMapping

## Buile & Flash  
brew tap osx-cross/avr  
brew tap PX4/homebrew-px4  
brew update  
brew install avr-gcc  
brew install dfu-programmer  
brew install gcc-arm-none-eabi  
brew install dfu-util  
make planck/rev6:zipper:dfu-util  
  
## Layout
![result](https://github.com/zipperr/PlanckKeyboardMapping/blob/master/keyboard-layout.png) 
 
## Remark
・US配列mac, US配列win, JIS配列mac, JIS配列winに対応  
・JIS配列で認識中はUS配列と同じキーを送信  
・Lower, Raiseキー押下時、変換+かな、無変+英数も合わせて送信 
 
## 既知の不具合
・JISモード時の;:'"が長押しに対応しない  
・"を連続で入力できない  
・US配列win時、ワンショットでIME切り替えができない(US配列には変換、無変換キーが無い為)  
・JISモードに切り替えた時PCBから変な音がする
