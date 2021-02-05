const char error_HTML[] PROGMEM = R"=====(
<html>
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
  width:95%;
}  

</Style>
    
<head>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Free Wi-Fi Gateway</title>
    </head>
<div>
<body>
        <form action="." method="GET">
        <p class="en">
        <h1><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAEgAAABIAQMAAABvIyEEAAAABlBMVEUAAABTU1OoaSf/AAAAAXRSTlMAQObYZgAAAENJREFUeF7tzbEJACEQRNGBLeAasBCza2lLEGx0CxFGG9hBMDDxRy/72O9FMnIFapGylsu1fgoBdkXfUHLrQgdfrlJN1BdYBjQQm3UAAAAASUVORK5CYII=" </img> This site can't be reached</h1>
        <p>Try:</p>
        <ul>
        <li>Checking the connection</li>
        <li>Checking the proxy and firewall</li>
        <li>Running Network Diagnostics</li>
        </ul>
        <h3><span style="color: #0000ff;">ERROR_CONNECTION_REFUSED<br>=ALL_SERVERS_BUSY</span></h3>
            
            <footer>
                <input type="submit" class="button" value="OK" />
            </footer>
        </form>
</body>
</div>
</html>
)=====";
