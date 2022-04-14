-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimuldb
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idAsiakas` int NOT NULL AUTO_INCREMENT,
  `Nimi` varchar(45) NOT NULL,
  `Osoite` varchar(45) NOT NULL,
  `Puhelinnumero` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`idAsiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (3,'Teppo Mustonen','Torikatu 5','0401234444'),(4,'Petteri Järvi','Aukionkatu 9','0445559889'),(5,'Petteri Järvi','Aukionkatu 9','0445559889');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakastili`
--

DROP TABLE IF EXISTS `asiakastili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakastili` (
  `idAsiakas` int NOT NULL,
  `idtili` int NOT NULL,
  PRIMARY KEY (`idAsiakas`,`idtili`),
  KEY `fk_asiakastili_tili1_idx` (`idtili`),
  CONSTRAINT `fk_asiakastili_asiakas1` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`),
  CONSTRAINT `fk_asiakastili_tili1` FOREIGN KEY (`idtili`) REFERENCES `tili` (`idtili`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakastili`
--

LOCK TABLES `asiakastili` WRITE;
/*!40000 ALTER TABLE `asiakastili` DISABLE KEYS */;
INSERT INTO `asiakastili` VALUES (3,3),(4,3),(4,4);
/*!40000 ALTER TABLE `asiakastili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `idKortti` int NOT NULL AUTO_INCREMENT,
  `Korttinumero` varchar(20) DEFAULT NULL,
  `Pin` varchar(255) DEFAULT NULL,
  `idAsiakas` int NOT NULL,
  `idtili` int NOT NULL,
  PRIMARY KEY (`idKortti`),
  UNIQUE KEY `Korttinumero` (`Korttinumero`),
  KEY `fk_kortti_asiakas_idx` (`idAsiakas`),
  KEY `fk_kortti_tili1_idx` (`idtili`),
  CONSTRAINT `fk_kortti_asiakas` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`),
  CONSTRAINT `fk_kortti_tili1` FOREIGN KEY (`idtili`) REFERENCES `tili` (`idtili`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (1,'901234','$2a$10$DW5KQrJRZ0.T/1YM.MEdT.J7ee1TjVgXBDkO/tC08E8PQKHE5hOEG',3,3),(6,'42316','$2a$10$IYHu/Y0b6zugV1f7UdKh8.mlXcSh0fc3mxbE5qv/XBdWPxagsNzr2',4,3),(7,'52255','$2a$10$xW32n7HilaSzF5228tULxucrCquhidgVt8dJhEzxo9vZcyevNJXo.',4,4);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idtili` int NOT NULL AUTO_INCREMENT,
  `Saldo` float NOT NULL,
  `Tilinumero` varchar(45) NOT NULL,
  PRIMARY KEY (`idtili`),
  UNIQUE KEY `Tilinumero_UNIQUE` (`Tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (3,36069.2,'123'),(4,220.5,'5678');
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtumat`
--

DROP TABLE IF EXISTS `tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtumat` (
  `idtilitapahtumat` int NOT NULL AUTO_INCREMENT,
  `Kortinnumero` varchar(45) NOT NULL,
  `Paivays` datetime NOT NULL,
  `Tapahtuma` varchar(45) NOT NULL,
  `Summa` float NOT NULL,
  `idkortti` int NOT NULL,
  `idtili` int NOT NULL,
  PRIMARY KEY (`idtilitapahtumat`),
  KEY `fk_tilitapahtumat_tili1_idx` (`idtili`),
  CONSTRAINT `fk_tilitapahtumat_tili1` FOREIGN KEY (`idtili`) REFERENCES `tili` (`idtili`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-04-14 11:23:09
