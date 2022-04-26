const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.Korttinumero && request.body.pin){
      const user = request.body.Korttinumero;
      const pin = request.body.pin;
        login.checkPin(user, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  const token = generateAccessToken({ Korttinumero: user });
                  response.send(token);
                }
                else {
                    console.log("wrong pin");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("Korttinumero does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("Korttinumero or pin missing");
      response.send(false);
    }
  }
);

function generateAccessToken(Korttinumero) {
  dotenv.config();
  return jwt.sign(Korttinumero, process.env.MY_TOKEN, { expiresIn: '3456000s' });
}

module.exports=router;

module.exports=router;