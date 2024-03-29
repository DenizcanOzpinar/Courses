USE [master]
GO
/****** Object:  Database [cs434DataBase]    Script Date: 7.01.2021 21:22:47 ******/
CREATE DATABASE [cs434DataBase]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'cs434DataBase', FILENAME = N'F:\Database\cs434DataBase.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'cs434DataBase_log', FILENAME = N'F:\Database\cs434DataBase_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [cs434DataBase] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [cs434DataBase].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [cs434DataBase] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [cs434DataBase] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [cs434DataBase] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [cs434DataBase] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [cs434DataBase] SET ARITHABORT OFF 
GO
ALTER DATABASE [cs434DataBase] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [cs434DataBase] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [cs434DataBase] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [cs434DataBase] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [cs434DataBase] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [cs434DataBase] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [cs434DataBase] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [cs434DataBase] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [cs434DataBase] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [cs434DataBase] SET  DISABLE_BROKER 
GO
ALTER DATABASE [cs434DataBase] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [cs434DataBase] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [cs434DataBase] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [cs434DataBase] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [cs434DataBase] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [cs434DataBase] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [cs434DataBase] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [cs434DataBase] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [cs434DataBase] SET  MULTI_USER 
GO
ALTER DATABASE [cs434DataBase] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [cs434DataBase] SET DB_CHAINING OFF 
GO
ALTER DATABASE [cs434DataBase] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [cs434DataBase] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [cs434DataBase] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [cs434DataBase] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [cs434DataBase] SET QUERY_STORE = OFF
GO
USE [cs434DataBase]
GO
/****** Object:  User [DE]    Script Date: 7.01.2021 21:22:47 ******/
CREATE USER [DE] FOR LOGIN [DE] WITH DEFAULT_SCHEMA=[DE]
GO
ALTER ROLE [db_owner] ADD MEMBER [DE]
GO
/****** Object:  Schema [DE]    Script Date: 7.01.2021 21:22:47 ******/
CREATE SCHEMA [DE]
GO
/****** Object:  Table [dbo].[store]    Script Date: 7.01.2021 21:22:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[store](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[name] [varchar](50) NOT NULL,
	[descr] [varchar](max) NULL,
	[quant] [int] NOT NULL,
	[provider] [varchar](max) NULL,
	[price] [float] NOT NULL,
	[pquant] [int] NULL,
	[pprice] [float] NULL,
	[place] [varchar](max) NULL,
	[qevalue] [varchar](50) NULL,
 CONSTRAINT [PK_Table_1] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[store] ON 

INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (27, N'micro S1420', N'micro chip No S1420', 0, N'TMCC', 0, 10000, 0, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (28, N'micro S1421', N'micro chip No S1421', 150, N'TMCC', 9.2, 10000, 10.2, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (29, N'micro S1422', N'micro chip No S1422', 300, N'TMCC', 18.4, 10000, 20.4, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (30, N'micro S1423', N'micro chip No S1423', 450, N'TMCC', 27.599999999999998, 10000, 30.599999999999998, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (31, N'micro S1424', N'micro chip No S1424', 600, N'TMCC', 36.8, 10000, 40.8, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (32, N'micro S1425', N'micro chip No S1425', 750, N'TMCC', 46, 10000, 51, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (33, N'micro S1426', N'micro chip No S1426', 900, N'TMCC', 55.199999999999996, 10000, 61.199999999999996, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (34, N'micro S1427', N'micro chip No S1427', 1050, N'TMCC', 64.399999999999991, 10000, 71.399999999999991, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (35, N'micro S1428', N'micro chip No S1428', 1200, N'TMCC', 73.6, 10000, 81.6, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (36, N'micro S1429', N'micro chip No S1429', 1350, N'TMCC', 82.8, 10000, 91.8, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (37, N'micro S14210', N'micro chip No S14210', 1500, N'TMCC', 92, 10000, 102, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (38, N'micro S14211', N'micro chip No S14211', 1650, N'TMCC', 101.19999999999999, 10000, 112.19999999999999, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (39, N'micro S14212', N'micro chip No S14212', 1800, N'TMCC', 110.39999999999999, 10000, 122.39999999999999, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (40, N'micro S14213', N'micro chip No S14213', 1950, N'TMCC', 119.6, 10000, 132.6, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (41, N'micro S14214', N'micro chip No S14214', 2100, N'TMCC', 128.79999999999998, 10000, 142.79999999999998, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (42, N'micro S14215', N'micro chip No S14215', 2250, N'TMCC', 138, 10000, 153, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (43, N'micro S14216', N'micro chip No S14216', 2400, N'TMCC', 147.2, 10000, 163.2, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (44, N'micro S14217', N'micro chip No S14217', 2550, N'TMCC', 156.39999999999998, 10000, 173.39999999999998, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (45, N'micro S14218', N'micro chip No S14218', 2700, N'TMCC', 165.6, 10000, 183.6, N'depo 1', N'0')
INSERT [dbo].[store] ([id], [name], [descr], [quant], [provider], [price], [pquant], [pprice], [place], [qevalue]) VALUES (46, N'micro S14219', N'micro chip No S14219', 2850, N'TMCC', 174.79999999999998, 10000, 193.79999999999998, N'depo 1', N'0')
SET IDENTITY_INSERT [dbo].[store] OFF
GO
USE [master]
GO
ALTER DATABASE [cs434DataBase] SET  READ_WRITE 
GO
