
const char* ssid = "WhoMe...";
const char* password =  "ohhidontcare";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len){
 
  if(type == WS_EVT_CONNECT){
    Serial.println("Websocket client connection received");
    client->text("Hello from ESP32 Server");
  } else if(type == WS_EVT_DISCONNECT){
    Serial.println("Client disconnected");
  }
  else if(type == WS_EVT_DATA){
      Serial.print("Message on WS");
      char buffer[len+1];
      snprintf(buffer,len+1, "%s", (char *)data);
      buffer[len] = '\0';
      Serial.println(buffer);
      parseMessage(String(buffer));
  }
}

void server_setup(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
  ws.onEvent(onWsEvent);
  server.addHandler(&ws);
  server.begin();
}

void server_loop(){

}



void parseMessage(String DIR){
        if (DIR.equals("RI"))
        {
                Serial.println("Going RIGHT");
                TurnRight();
        }
        else if (DIR.equals("LF"))
        {       Serial.println("Going Left");
                TurnLeft();
        }
        else if (DIR.equals("FW"))
        {
                Serial.println("Going FW");
                GoFrwrd();
        }
        else if (DIR.equals("BW"))
        {
                Serial.println("Going Back");
                GoBack();
        }
        else if (DIR.equals("STOP"))
        {       Serial.println("Stopping");
                Stop();
        }
}
