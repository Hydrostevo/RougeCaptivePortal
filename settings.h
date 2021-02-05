// Settings
    const char SETTINGS_HTML[] PROGMEM = R"=====(

<html>
<head>
<title>Settings page</title>
</head>
<body>
<h1>Settings</h1><br>
<p><a href='/logs'><- Back to Log page</a></p>
<p><a href=\"/esportal\"><- Back to Captive Portal</a></p>
<hr><h1>Select default phishing site</h1>
<form> <!-- action ="" method="get"-->
  <input type="radio" id="PORTAL_LOGIN_HTML" name="target" value="PORTAL_LOGIN_HTML">
  <label for="PORTAL_LOGIN_HTML">Generic portal </label>
<br>
  <input type="radio" id="GOOGLE_HTML" name="target" value="GOOGLE_HTML">
  <label for="GOOGLE_HTML">Google </label>
<br>
  <input type="radio" id="PLUSNET_HTML" name="target" value="PLUSNET_HTML">
  <label for="PLUSNET_HTML">Plusnet </label>
<br>
<input type="radio" id="BT_HTML" name="target" value="BT_HTML">
  <label for="BT_HTML">BT </label>
<br>
  <input type="radio" id="MICROSOFT_HTML" name="target" value="MICROSOFT_HTML">
  <label for="MICROSOFT_HTML">Microsoft </label>
<br>
  <input type="radio" id="SKY_HTML" name="target" value="SKY_HTML">
  <label for="SKY_HTML">Sky </label>
<br>
  <input type="radio" id="FACEBOOK_HTML" name="target" value="FACEBOOK_HTML">
  <label for="FACEBOOK_HTML">Facebook </label>
<br>
  <input type="radio" id="YAHOO_HTML" name="target" value="YAHOO_HTML">
  <label for="YAHOO_HTML">Yahoo </label>
<br>
<br>
<br>
  <input type="submit" value="Submit">  
</form>







</html>
)=====";
