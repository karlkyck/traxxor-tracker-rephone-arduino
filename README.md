## Traxxor GPS Tracker for RePhone
A simple GPS tracker written in Arduino for the [RePhone](http://wiki.seeed.cc/RePhone/).

The tracker uses a SIM card to send and receive SMS messages.
When the tracker receives an SMS message in a certain format it will reply to the sender via SMS with its current geo coordinates.
  
## Prerequisites 
To compile and run this code you will need:

* A [RePhone Geo Kit](https://www.seeedstudio.com/RePhone-Geo-Kit-p-2624.html)
* A working SIM card 
* [Arduino IDE for RePhone](http://wiki.seeed.cc/Arduino_IDE_for_RePhone_Kit/)

## Assembly
Assemble the RePhone Geo Kit as per the [instructions](http://wiki.seeed.cc/RePhone_Geo_Kit/).
Insert the SIM card into the RePhone.

## Upload Program
To load this program onto your RePhone, open the `traxxor.ino` file in your Arduino IDE.
From the `Tools > Port` menu select the correct port your RePhone.
From the `Tools > Board` menu make sure that Rephone is selected.
Then click the Upload button:
 
![picture of upload button](https://raw.githubusercontent.com/SeeedDocument/Arduino_IDE_for_RePhone_Kit/master/img/Arduino_IDE_for_RePhone_upload.png)

## Receiving Tracking Information
Now send an SMS message with the content `L` to the tracker.

In a few minutes you should receive a response with the format:
 
`N/S:latitude,E/W:longitude`