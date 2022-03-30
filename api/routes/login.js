const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.idKortti && request.body.pin){
      const user = request.body.idKortti;
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
                  const token = generateAccessToken({ idKortti: user });
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
              console.log("idKortti does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("idKortti or pin missing");
      response.send(false);
    }
  }
);

function generateAccessToken(idKortti) {
  dotenv.config();
  return jwt.sign(idKortti, process.env.MY_TOKEN, { expiresIn: '3456000s' });
}

module.exports=router;

module.exports=router;