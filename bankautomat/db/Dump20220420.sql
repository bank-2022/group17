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
INSERT INTO `asiakas` VALUES (3,'Teppo Mustonen','Torikatu 5','0401234444'),(4,'Petteri Järvi','Aukionkatu 9','0445559889');
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
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (1,'901234','$2a$10$DW5KQrJRZ0.T/1YM.MEdT.J7ee1TjVgXBDkO/tC08E8PQKHE5hOEG',3,3),(6,'42316','$2a$10$IYHu/Y0b6zugV1f7UdKh8.mlXcSh0fc3mxbE5qv/XBdWPxagsNzr2',4,3),(11,'52255BC','$2a$10$IVWjGw4HAF4Pgqq/esU/auNKvxx9JNthJAP8nPIUtzqBoB5GNK3p2',4,4);
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
INSERT INTO `tili` VALUES (3,35291.5,'123'),(4,220.5,'5678');
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
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
INSERT INTO `tilitapahtumat` VALUES (3,'901234','2022-04-16 20:09:37','nosto',210.5,1,3),(4,'901234','2022-04-16 20:27:19','nosto',210.5,1,3),(5,'901234','2022-04-16 20:28:22','talletus',111.1,1,3),(6,'901234','2022-04-16 20:28:31','talletus',111.1,1,3),(7,'901234','2022-04-18 12:09:30','nosto',210.5,1,3),(8,'901234','2022-04-18 12:42:36','nosto',210.5,1,3),(9,'901234','2022-04-19 01:01:13','nosto',111.1,1,3),(10,'52255BC','2022-04-19 19:06:09','nosto',111.1,1,3),(11,'52255BC','2022-04-19 19:06:26','nosto',111.1,1,3),(12,'52255BC','2022-04-19 19:06:27','nosto',111.1,1,3),(13,'52255BC','2022-04-19 19:06:27','nosto',111.1,1,3),(14,'52255BC','2022-04-19 19:12:33','nosto',111.1,11,3),(15,'52255BC','2022-04-19 19:20:50','nosto',111.1,11,3),(16,'52255BC','2022-04-19 19:20:57','nosto',111.1,11,3),(17,'52255BC','2022-04-19 19:20:58','nosto',111.1,11,3),(18,'901234','2022-04-19 19:30:26','nosto',111.1,1,3),(19,'901234','2022-04-20 12:23:39','nosto',111.1,1,3),(20,'901234','2022-04-20 12:24:05','talletus',111.1,11,3),(21,'52255BC','2022-04-20 12:31:20','talletus',111.1,11,3),(22,'52255BC','2022-04-20 12:31:22','talletus',111.1,11,3),(23,'42316','2022-04-20 12:33:53','talletus',111.1,6,3),(24,'42316','2022-04-20 12:33:55','talletus',111.1,6,3),(25,'42316','2022-04-20 12:33:56','nosto',111.1,6,3),(26,'42316','2022-04-20 12:33:57','nosto',111.1,6,3),(27,'42316','2022-04-20 12:33:57','nosto',111.1,6,3),(28,'42316','2022-04-20 12:33:58','nosto',111.1,6,3),(29,'42316','2022-04-20 12:33:58','nosto',111.1,6,3),(30,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(31,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(32,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(33,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(34,'42316','2022-04-20 12:34:00','nosto',111.1,6,3),(35,'42316','2022-04-20 12:34:00','nosto',111.1,6,3),(36,'42316','2022-04-20 13:38:33','talletus',111.1,6,3),(37,'42316','2022-04-20 13:38:36','nosto',111.1,6,3);
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'banksimuldb'
--
/*!50003 DROP PROCEDURE IF EXISTS `nosta` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `nosta`(IN tili_id INT, IN amount FLOAT, IN Kortinnumero VARCHAR(45), IN kortti_id INT)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE tili SET Saldo=Saldo-amount WHERE idtili=tili_id AND Saldo >= amount;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tilitapahtumat(Kortinnumero,Tapahtuma,Summa,Paivays, idkortti, idtili) VALUES(Kortinnumero,'nosto',amount,NOW(),kortti_id, tili_id);
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `talleta` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `talleta`(IN tili_id INT, IN amount FLOAT, IN Kortinnumero VARCHAR(45), IN kortti_id INT)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE tili SET Saldo=Saldo+amount WHERE idtili=tili_id;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tilitapahtumat(Kortinnumero,Tapahtuma,Summa,Paivays, idkortti, idtili) VALUES(Kortinnumero,'talletus',amount,NOW(),kortti_id, tili_id);
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-04-20 13:44:07
