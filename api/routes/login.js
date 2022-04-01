const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
<<<<<<< HEAD
    if(request.body.Korttinumero && request.body.pin){
      const user = request.body.Korttinumero;
      const pin = request.body.pin;
=======
    if(request.body.idKortti && request.body.Pin){
      const user = request.body.idKortti;
      const Pin = request.body.Pin;
      
>>>>>>> f9d4b1b (Restapi)
        login.checkPin(user, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
<<<<<<< HEAD
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  const token = generateAccessToken({ Korttinumero: user });
                  response.send(token);
                }
                else {
                    console.log("wrong pin");
=======
              bcrypt.compare(Pin,dbResult[0].Pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  const token = generateAccessToken({ idKortti: user });
                  response.send(token);
                }
                else {
                    console.log("wrong Pin");
                    console.log(Pin);
>>>>>>> f9d4b1b (Restapi)
                    response.send(false);
                }			
              }
              );
            }
            else{
<<<<<<< HEAD
              console.log("Korttinumero does not exists");
=======
              console.log("idKortti does not exists");
>>>>>>> f9d4b1b (Restapi)
              response.send(false);
            }
          }
          }
        );
      }
    else{
<<<<<<< HEAD
      console.log("Korttinumero or pin missing");
=======
      console.log("idKortti or Pin missing");
>>>>>>> f9d4b1b (Restapi)
      response.send(false);
    }
  }
);

<<<<<<< HEAD
function generateAccessToken(Korttinumero) {
  dotenv.config();
  return jwt.sign(Korttinumero, process.env.MY_TOKEN, { expiresIn: '3456000s' });
}

module.exports=router;

=======
function generateAccessToken(idKortti) {
  dotenv.config();
  return jwt.sign(idKortti, process.env.MY_TOKEN, { expiresIn: '1800000s' });
}

>>>>>>> f9d4b1b (Restapi)
module.exports=router;