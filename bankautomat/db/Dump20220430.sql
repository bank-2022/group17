CREATE DATABASE  IF NOT EXISTS `banksimuldb` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `banksimuldb`;
-- MySQL dump 10.13  Distrib 8.0.27, for Win64 (x86_64)
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
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (3,'Teppo Mustonen','Torikatu 5','0401234444'),(4,'Petteri Järvi','Aukionkatu 9','0445559889'),(6,'Ossi Opiskelija','Yliopistokatu 9','0206110666');
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
INSERT INTO `asiakastili` VALUES (3,3),(4,3),(6,3),(4,4);
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
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (1,'901234','$2a$10$DW5KQrJRZ0.T/1YM.MEdT.J7ee1TjVgXBDkO/tC08E8PQKHE5hOEG',3,3),(6,'42316','$2a$10$IYHu/Y0b6zugV1f7UdKh8.mlXcSh0fc3mxbE5qv/XBdWPxagsNzr2',4,3),(11,'52255BC','$2a$10$IVWjGw4HAF4Pgqq/esU/auNKvxx9JNthJAP8nPIUtzqBoB5GNK3p2',4,4),(12,'0500CB615F','$2a$10$BHnVoeM41KWRgnRXrM7YT.GMxpFeIWw9p3vgG.q15sSEDKLNbGq.y',6,3);
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
INSERT INTO `tili` VALUES (3,910.5,'123'),(4,220.5,'5678');
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
) ENGINE=InnoDB AUTO_INCREMENT=97 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
INSERT INTO `tilitapahtumat` VALUES (3,'901234','2022-04-16 20:09:37','nosto',210.5,1,3),(4,'901234','2022-04-16 20:27:19','nosto',210.5,1,3),(5,'901234','2022-04-16 20:28:22','talletus',111.1,1,3),(6,'901234','2022-04-16 20:28:31','talletus',111.1,1,3),(7,'901234','2022-04-18 12:09:30','nosto',210.5,1,3),(8,'901234','2022-04-18 12:42:36','nosto',210.5,1,3),(9,'901234','2022-04-19 01:01:13','nosto',111.1,1,3),(10,'52255BC','2022-04-19 19:06:09','nosto',111.1,1,3),(11,'52255BC','2022-04-19 19:06:26','nosto',111.1,1,3),(12,'52255BC','2022-04-19 19:06:27','nosto',111.1,1,3),(13,'52255BC','2022-04-19 19:06:27','nosto',111.1,1,3),(14,'52255BC','2022-04-19 19:12:33','nosto',111.1,11,3),(15,'52255BC','2022-04-19 19:20:50','nosto',111.1,11,3),(16,'52255BC','2022-04-19 19:20:57','nosto',111.1,11,3),(17,'52255BC','2022-04-19 19:20:58','nosto',111.1,11,3),(18,'901234','2022-04-19 19:30:26','nosto',111.1,1,3),(19,'901234','2022-04-20 12:23:39','nosto',111.1,1,3),(20,'901234','2022-04-20 12:24:05','talletus',111.1,11,3),(21,'52255BC','2022-04-20 12:31:20','talletus',111.1,11,3),(22,'52255BC','2022-04-20 12:31:22','talletus',111.1,11,3),(23,'42316','2022-04-20 12:33:53','talletus',111.1,6,3),(24,'42316','2022-04-20 12:33:55','talletus',111.1,6,3),(25,'42316','2022-04-20 12:33:56','nosto',111.1,6,3),(26,'42316','2022-04-20 12:33:57','nosto',111.1,6,3),(27,'42316','2022-04-20 12:33:57','nosto',111.1,6,3),(28,'42316','2022-04-20 12:33:58','nosto',111.1,6,3),(29,'42316','2022-04-20 12:33:58','nosto',111.1,6,3),(30,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(31,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(32,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(33,'42316','2022-04-20 12:33:59','nosto',111.1,6,3),(34,'42316','2022-04-20 12:34:00','nosto',111.1,6,3),(35,'42316','2022-04-20 12:34:00','nosto',111.1,6,3),(36,'42316','2022-04-20 13:38:33','talletus',111.1,6,3),(37,'42316','2022-04-20 13:38:36','nosto',111.1,6,3),(38,'42316','2022-04-26 22:20:59','nosto',30000,6,3),(39,'42316','2022-04-26 22:21:05','talletus',500,6,3),(40,'42316','2022-04-26 22:45:58','nosto',100,6,3),(41,'42316','2022-04-26 22:58:38','nosto',110,6,3),(42,'42316','2022-04-26 22:58:51','nosto',60,6,3),(43,'42316','2022-04-26 22:58:51','nosto',60,6,3),(44,'42316','2022-04-26 22:59:17','nosto',50,6,3),(45,'42316','2022-04-26 22:59:23','nosto',100,6,3),(46,'42316','2022-04-26 22:59:23','nosto',100,6,3),(47,'42316','2022-04-26 23:03:03','nosto',110,6,3),(48,'42316','2022-04-26 23:03:06','nosto',110,6,3),(49,'42316','2022-04-26 23:03:06','nosto',110,6,3),(50,'42316','2022-04-26 23:03:10','nosto',200,6,3),(51,'42316','2022-04-26 23:03:10','nosto',200,6,3),(52,'42316','2022-04-26 23:03:10','nosto',200,6,3),(53,'42316','2022-04-26 23:05:22','nosto',100,6,3),(54,'42316','2022-04-26 23:05:23','nosto',100,6,3),(55,'42316','2022-04-26 23:05:23','nosto',100,6,3),(56,'42316','2022-04-26 23:05:55','nosto',60,6,3),(57,'42316','2022-04-26 23:05:57','talletus',80,6,3),(58,'42316','2022-04-26 23:05:59','nosto',100,6,3),(59,'42316','2022-04-26 23:05:59','nosto',100,6,3),(60,'42316','2022-04-26 23:08:14','nosto',100,6,3),(61,'42316','2022-04-26 23:08:15','nosto',40,6,3),(62,'42316','2022-04-26 23:08:18','nosto',40,6,3),(63,'42316','2022-04-26 23:08:28','nosto',500,6,3),(64,'42316','2022-04-28 12:39:34','nosto',110,6,3),(65,'42316','2022-04-28 12:39:53','nosto',100,6,3),(66,'42316','2022-04-28 12:39:58','nosto',100,6,3),(67,'42316','2022-04-28 12:40:52','nosto',110,6,3),(68,'42316','2022-04-28 12:42:01','nosto',110,6,3),(69,'42316','2022-04-28 12:42:19','nosto',110,6,3),(70,'42316','2022-04-28 12:42:40','nosto',110,6,3),(71,'42316','2022-04-28 12:42:51','nosto',200,6,3),(72,'42316','2022-04-28 12:53:18','nosto',100,6,3),(73,'42316','2022-04-28 12:54:28','nosto',100,6,3),(74,'42316','2022-04-28 12:54:54','nosto',100,6,3),(75,'42316','2022-04-28 12:55:09','nosto',50,6,3),(76,'42316','2022-04-28 12:59:46','nosto',20,6,3),(77,'42316','2022-04-28 12:59:50','nosto',100,6,3),(78,'42316','2022-04-28 12:59:55','nosto',110,6,3),(79,'42316','2022-04-28 13:00:01','nosto',600,6,3),(80,'42316','2022-04-28 13:00:07','talletus',1000,6,3),(81,'42316','2022-04-28 13:00:14','nosto',110,6,3),(82,'42316','2022-04-28 13:37:09','nosto',200,6,3),(83,'42316','2022-04-28 13:37:18','nosto',110,6,3),(84,'42316','2022-04-28 13:38:03','talletus',100,6,3),(85,'42316','2022-04-28 13:38:32','nosto',500,6,3),(86,'42316','2022-04-28 14:03:39','nosto',110,6,3),(87,'42316','2022-04-28 14:03:43','talletus',50,6,3),(88,'42316','2022-04-28 14:12:10','talletus',100,6,3),(89,'42316','2022-04-28 14:12:27','nosto',100,6,3),(90,'42316','2022-04-28 14:14:25','nosto',150,6,3),(91,'42316','2022-04-28 14:24:13','talletus',50,6,3),(92,'42316','2022-04-29 09:15:14','nosto',110,6,3),(93,'42316','2022-04-29 09:15:24','talletus',1000,6,3),(94,'42316','2022-04-30 14:24:30','nosto',500,6,3),(95,'42316','2022-04-30 14:25:01','talletus',9,6,3),(96,'0500CB615F','2022-04-30 14:41:17','nosto',500,12,3);
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'banksimuldb'
--

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

-- Dump completed on 2022-04-30 14:45:31
