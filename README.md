# Gaming glove using Arduino Uno
## Introduction
The gaming glove is a glove mounted with MPU6050 sensor on top of it and the tilting of the sensor in X-axis and Y-axis cause the action of key press. We can use it to play any running game like Subway Surfers which use A, S, D, W keys for moment. 
I connected X-axis with press of 'A' and 'D' key and on Y-axis with 'W' and 'S' key. To make it simple I have used only four keys but with MPU6050 sensor we can do much more than that so you can use your creativity to make it more fun by adding more functionality.

Note:- Arduino Uno and nano board can't use 'Keyboard' library for making keypress action because this boards do not have the necessary USB capabilities. So I have converted the Arduino into HID device by changing the firmware (hex files for changing the firmware is provided with this repo).
## Connections

Note:- Ignore the purple wire.

<img src="https://github.com/Pushpendra766/gaming-glove/blob/main/img/mpu6050connections.jpg" width="500" />

## Steps to get started :-
1. Follow the above connections and do it in your board.
1. Clone the repository in your local system or just download the zip file.
2. Open ```main_code.ino``` in you Arduino IDE and upload the code.<br>
Remember :- You may have to change the values of angles in the code to find perfect angle.
3. Install flip software by running the .exe file in the FLIP install folder.
4. Follow [this youtube video](https://youtu.be/tvqA-JcTQNg) tutorial and convert the Arduino into an HID device.<br/>
Remember : The code (for uploading in arduino board and not the hex file) in our case is different than this video so upload the code that I provided in this repo only.
5. Bind your game keys with A, S, D, W for the actions. 
5. You are ready to use your gaming glove.

## Final Project Image :-

<img src="https://github.com/Pushpendra766/gaming-glove/blob/main/img/gaming-glove.jpg" width="500" />

## Working Video
[Here](https://youtube.com/shorts/QUvwEcXfaEI?feature=share) is me using the glove while playing Subway Surfers.

## Want to contribute
This repository is open for contributions. So, if you have done some complicated stuff or any simple thing which makes it more fun and useful then you are welcome to do contribution to this repo.

## To convert back my Arduino board from HID device to normal 
You just need to follow [this](https://youtu.be/tvqA-JcTQNg) youtube tutorial with some changes. This time use the ```Arduino-usbserial-uno.hex``` hex file.

## Have any question 
Raise an issue in this repository.

### Show ❤️ by a 🌟 to this repository.
