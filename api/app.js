var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
<<<<<<< HEAD
var tiliRouter = require('./routes/tili');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');
var asiakasRouter = require('./routes/asiakas');
var korttiRouter = require('./routes/kortti');
var asiakastiliRouter = require('./routes/asiakastili');
var loginRouter = require('./routes/login');
=======
var asiakasRouter = require('./routes/asiakas');
var asiakastiliRouter = require('./routes/asiakastili');
var korttiRouter = require('./routes/kortti');
var loginRouter = require('./routes/login');
var tiliRouter = require('./routes/tili');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');


>>>>>>> f9d4b1b (Restapi)


const helmet = require('helmet');
const cors = require('cors');
const jwt = require('jsonwebtoken');

var app = express(); 

app.use(helmet());
app.use(cors());

app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/login', loginRouter);
<<<<<<< HEAD
app.use(authenticateToken);
app.use('/tili', tiliRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);
app.use('/asiakas', asiakasRouter);
app.use('/kortti', korttiRouter);
app.use('/asiakastili', asiakastiliRouter);
=======

app.use(authenticateToken);
app.use('/asiakas', asiakasRouter);
app.use('/asiakastili', asiakastiliRouter);
app.use('/kortti', korttiRouter);
app.use('/tili', tiliRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);

>>>>>>> f9d4b1b (Restapi)

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }

module.exports = app;
