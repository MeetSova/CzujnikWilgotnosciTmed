const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>

<div id="demo">
<h1>The ESP32 NodeMCU Update web page without refresh</h1>
  <button type="button" onclick="sendData(1)">LED ON</button>
  <button type="button" onclick="sendData(0)">LED OFF</button><BR>

  <button type="button" onclick="sendData1(1)">LED ON</button>
  <button type="button" onclick="sendData1(0)">LED OFF</button><BR>
</div>

<div>
    LED State is : <span id="LEDState">NA</span>
    LED State is : <span id="LEDState1">NA</span>
</div>

<iframe width="854" height="480" style="border: none" src="http://83.230.12.40:356/video"></iframe>
<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  xhttp.send();
}

function sendData1(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState1").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED1?LEDstate1="+led, true);
  xhttp.send();
}
</script>
</body>
</html>
)=====";
