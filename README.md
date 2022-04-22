# group17   |   Bankautomat

## Asennusohje
aja api kansiossa komento npm install. Sitten sovellus käynnistyy komennolla npm start

### .env

Luo api kansioon tiedosto .env ja kirjoita sinne muuttuja nimeltään MY_TOKEN.
Aja komentoriviltä komento node create_token.js ja kopsaa "token" muuttujaan MY_TOKEN

### Tietokanta

Suorita tuo tiedosto "database_dump.sql" ja aja komennot 
<b>
CREATE USER 'netuser'@'localhost' IDENTIFIED WITH mysql_native_password BY 'netpass'
GRANT ALL ON banksimuldb.* to 'netuser'@'localhost';
<b>

## ER-Kaavio

<img src="Documents/banksimulERDiagram">
