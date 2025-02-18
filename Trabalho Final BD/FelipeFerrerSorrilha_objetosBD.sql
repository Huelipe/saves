-- MySQL dump 10.13  Distrib 8.0.40, for Linux (x86_64)
--
-- Host: localhost    Database: imobiliaria
-- ------------------------------------------------------
-- Server version	8.0.40-0ubuntu0.22.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `alugueis`
--

DROP TABLE IF EXISTS `alugueis`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `alugueis` (
  `id_inquilino` int NOT NULL,
  `id_imovel` int NOT NULL,
  `data_inicio` date NOT NULL,
  `data_fim` date DEFAULT NULL,
  `valor_aluguel` decimal(10,2) NOT NULL,
  PRIMARY KEY (`id_inquilino`,`id_imovel`),
  KEY `id_imovel` (`id_imovel`),
  CONSTRAINT `alugueis_ibfk_1` FOREIGN KEY (`id_inquilino`) REFERENCES `inquilinos` (`id`) ON DELETE CASCADE,
  CONSTRAINT `alugueis_ibfk_2` FOREIGN KEY (`id_imovel`) REFERENCES `imoveis` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `alugueis`
--

LOCK TABLES `alugueis` WRITE;
/*!40000 ALTER TABLE `alugueis` DISABLE KEYS */;
/*!40000 ALTER TABLE `alugueis` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `atendimentos_inquilino_corretor`
--

DROP TABLE IF EXISTS `atendimentos_inquilino_corretor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `atendimentos_inquilino_corretor` (
  `id_inquilino` int NOT NULL,
  `id_corretor` int NOT NULL,
  PRIMARY KEY (`id_inquilino`,`id_corretor`),
  KEY `id_corretor` (`id_corretor`),
  CONSTRAINT `atendimentos_inquilino_corretor_ibfk_1` FOREIGN KEY (`id_inquilino`) REFERENCES `inquilinos` (`id`) ON DELETE CASCADE,
  CONSTRAINT `atendimentos_inquilino_corretor_ibfk_2` FOREIGN KEY (`id_corretor`) REFERENCES `corretores` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `atendimentos_inquilino_corretor`
--

LOCK TABLES `atendimentos_inquilino_corretor` WRITE;
/*!40000 ALTER TABLE `atendimentos_inquilino_corretor` DISABLE KEYS */;
/*!40000 ALTER TABLE `atendimentos_inquilino_corretor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `contatos_proprietario_corretor`
--

DROP TABLE IF EXISTS `contatos_proprietario_corretor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `contatos_proprietario_corretor` (
  `id_proprietario` int NOT NULL,
  `id_corretor` int NOT NULL,
  PRIMARY KEY (`id_proprietario`,`id_corretor`),
  KEY `id_corretor` (`id_corretor`),
  CONSTRAINT `contatos_proprietario_corretor_ibfk_1` FOREIGN KEY (`id_proprietario`) REFERENCES `proprietarios` (`id`) ON DELETE CASCADE,
  CONSTRAINT `contatos_proprietario_corretor_ibfk_2` FOREIGN KEY (`id_corretor`) REFERENCES `corretores` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `contatos_proprietario_corretor`
--

LOCK TABLES `contatos_proprietario_corretor` WRITE;
/*!40000 ALTER TABLE `contatos_proprietario_corretor` DISABLE KEYS */;
/*!40000 ALTER TABLE `contatos_proprietario_corretor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `corretores`
--

DROP TABLE IF EXISTS `corretores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `corretores` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(100) NOT NULL,
  `creci` varchar(20) NOT NULL,
  `email` varchar(100) NOT NULL,
  `telefone` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `creci` (`creci`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `corretores`
--

LOCK TABLES `corretores` WRITE;
/*!40000 ALTER TABLE `corretores` DISABLE KEYS */;
/*!40000 ALTER TABLE `corretores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `imoveis`
--

DROP TABLE IF EXISTS `imoveis`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `imoveis` (
  `id` int NOT NULL AUTO_INCREMENT,
  `endereco` varchar(255) NOT NULL,
  `tipo` enum('Casa','Apartamento','Terreno','Comercial') NOT NULL,
  `valor` decimal(10,2) NOT NULL,
  `id_proprietario` int NOT NULL,
  PRIMARY KEY (`id`),
  KEY `id_proprietario` (`id_proprietario`),
  CONSTRAINT `imoveis_ibfk_1` FOREIGN KEY (`id_proprietario`) REFERENCES `proprietarios` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `imoveis`
--

LOCK TABLES `imoveis` WRITE;
/*!40000 ALTER TABLE `imoveis` DISABLE KEYS */;
/*!40000 ALTER TABLE `imoveis` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `inquilinos`
--

DROP TABLE IF EXISTS `inquilinos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `inquilinos` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `telefone` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `inquilinos`
--

LOCK TABLES `inquilinos` WRITE;
/*!40000 ALTER TABLE `inquilinos` DISABLE KEYS */;
/*!40000 ALTER TABLE `inquilinos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proprietarios`
--

DROP TABLE IF EXISTS `proprietarios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `proprietarios` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nome` varchar(100) NOT NULL,
  `email` varchar(100) NOT NULL,
  `telefone` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proprietarios`
--

LOCK TABLES `proprietarios` WRITE;
/*!40000 ALTER TABLE `proprietarios` DISABLE KEYS */;
/*!40000 ALTER TABLE `proprietarios` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-02-02 19:23:43
