var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');

var indexRouter = require('./routes/index');
var asiakasRouter = require('./routes/asiakas');
var korttiRouter = require('./routes/kortti');
var tiliRouter = require('./routes/tili');
var asiakastiliRouter = require('./routes/asiakastili');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');
var loginRouter = require('./routes/login');
//var userRouter = require('./routes/user');

var app = express();



app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/asiakas', asiakasRouter);
app.use('/kortti', korttiRouter);
app.use('/tili', tiliRouter);
app.use('/asiakastili', asiakastiliRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);
app.use('/login', loginRouter);
//app.use('/user', userRouter);

module.exports = app;
