#include 
#include 
int greenled = 4;
int redled = 5;
int whiteled = 6;
int yellowled = 7;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //mac address
byte ip[] = { 192, 168, 0, 13 };                      // Lan IP
byte gateway[] = { 192, 168, 0, 1 };                   // gateway IP
byte subnet[] = { 255, 255, 255, 0 };                  
EthernetServer server(80);                             
String buffer;

void setup() {
 Serial.begin(9600);
 pinMode(greenled, OUTPUT);
 pinMode(redled, OUTPUT);
 pinMode(whiteled, OUTPUT);
 pinMode(yellowled, OUTPUT);
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient ethernet_shield = server.available();
  if (ethernet_shield) {
    while (ethernet_shield.connected()) {   
      if (ethernet_shield.available()) {
        char c = ethernet_shield.read();
        if (buffer.length() &lt; 100) {
          buffer += c;
           }

           if (c == '\n') {          
           Serial.println(buffer); 
           ethernet_shield.println("HTTP/1.1 200 OK"); 
           ethernet_shield.println("Content-Type: text/html");
           ethernet_shield.println();     
           ethernet_shield.println("");
           ethernet_shield.println("");
           ethernet_shield.println("Leds Controlled by webpage");
           ethernet_shield.println("");
           ethernet_shield.println(""); 
           ethernet_shield.println("</pre>
<h2>Controlling Leds through Webpage</h2>
");
ethernet_shield.println("
");
ethernet_shield.println("
<h4 style="color: lightgreen;">Green LED</h4>
");
ethernet_shield.println("<a href="\&quot;/?greenledon\&quot;\&quot;"><button style="background-color: lightgreen; border-radius: 12px;"> ON</button></a>");
ethernet_shield.println("<a href="\&quot;/?greenledoff\&quot;\&quot;"><button style="background-color: lightgreen; border-radius: 12px;"> OFF</button></a>
");
ethernet_shield.println("
");
ethernet_shield.println("
<h4 style="color: #f44336;">Red LED</h4>
");
ethernet_shield.println("<a href="\&quot;/?redledon\&quot;\&quot;"><button style="background-color: #f44336; border-radius: 12px;"> ON</button></a>");
ethernet_shield.println("<a href="\&quot;/?redledoff\&quot;\&quot;"><button style="background-color: #f44336; border-radius: 12px;"> OFF</button></a>
");
ethernet_shield.println("
");
ethernet_shield.println("
<h4>White LED</h4>
");
ethernet_shield.println("<a href="\&quot;/?whiteledon\&quot;\&quot;"><button style="border-radius: 12px;"> ON</button></a>");
ethernet_shield.println("<a href="\&quot;/?whiteledoff\&quot;\&quot;"><button style="border-radius: 12px;"> OFF</button></a>
");
ethernet_shield.println("
");
ethernet_shield.println("
<h4 style="color: yellow;">Yellow LED</h4>
");
ethernet_shield.println("<a href="\&quot;/?yellowledon\&quot;\&quot;"><button style="background-color: yellow; border-radius: 12px;"> ON</button></a>");
ethernet_shield.println("<a href="\&quot;/?yellowledoff\&quot;\&quot;"><button style="background-color: yellow; border-radius: 12px;"> OFF</button></a>
");
ethernet_shield.println("
");
ethernet_shield.println("
<pre>");
           ethernet_shield.println("");
     
           delay(1);
           ethernet_shield.stop();
           
           if (buffer.indexOf("?greenledon") &gt;0){
               digitalWrite(greenled, HIGH);
           }
            if (buffer.indexOf("?greenledoff") &gt;0){
               digitalWrite(greenled, LOW);
           }
            if (buffer.indexOf("?redledon") &gt;0){
               digitalWrite(redled, HIGH);
           }
            if (buffer.indexOf("?redledoff") &gt;0){
               digitalWrite(redled, LOW);
           }
            if (buffer.indexOf("?whiteledon") &gt;0){
               digitalWrite(whiteled, HIGH);
           }
            if (buffer.indexOf("?whiteledoff") &gt;0){
               digitalWrite(whiteled, LOW);
           }
            if (buffer.indexOf("?yellowledon") &gt;0){
               digitalWrite(yellowled, HIGH);
           }
            if (buffer.indexOf("?yellowledoff") &gt;0){
               digitalWrite(yellowled, LOW);
           }
            //clearing string for next read
            buffer="";  
           
         }
       }
    }
  }
}
