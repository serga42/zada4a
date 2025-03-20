-- phpMyAdmin SQL Dump
-- version 5.1.2
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Мар 20 2025 г., 18:35
-- Версия сервера: 5.7.24
-- Версия PHP: 8.3.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `github`
--

-- --------------------------------------------------------

--
-- Структура таблицы `books`
--

CREATE TABLE `books` (
  `ID` int(11) NOT NULL,
  `Publisher` varchar(255) DEFAULT NULL,
  `Author` varchar(255) DEFAULT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Price` decimal(65,0) DEFAULT NULL,
  `Genre` varchar(255) DEFAULT NULL,
  `Release_date` date DEFAULT NULL,
  `Pegi` varchar(255) DEFAULT NULL,
  `Photo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `books`
--

INSERT INTO `books` (`ID`, `Publisher`, `Author`, `Name`, `Price`, `Genre`, `Release_date`, `Pegi`, `Photo`) VALUES
(1, 'АСТ', 'Чак Паланик', 'Бойцовский клуб', '500', 'Роман', '2022-06-12', '18+', 'image.jpg'),
(2, 'АСТ', 'Джордж Оруэлл', '1984', '700', 'Роман', '2023-07-25', '18+', 'image.jpg'),
(3, 'Азбука', 'Мур Алан', 'V значит Vендетта', '2000', 'Роман', '2022-01-29', '18+', 'image.jpg'),
(4, 'Эксмо', 'Пьюзо Марио', 'Крёстный отец', '300', 'Роман', '2023-03-19', '18+', 'image.jpg'),
(5, 'Эксмо', 'Рэй Брэрбери', '451 градус по фаренгейту', '400', 'Роман', '2023-05-05', '18+', 'image.jpg');

-- --------------------------------------------------------

--
-- Структура таблицы `clothes`
--

CREATE TABLE `clothes` (
  `ID` int(11) NOT NULL,
  `Brand` varchar(255) DEFAULT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Price` decimal(65,0) DEFAULT NULL,
  `Type_of_product` varchar(255) DEFAULT NULL,
  `Size` varchar(255) DEFAULT NULL,
  `Gender` varchar(255) DEFAULT NULL,
  `For_child` tinyint(1) DEFAULT NULL,
  `Photo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `clothes`
--

INSERT INTO `clothes` (`ID`, `Brand`, `Name`, `Price`, `Type_of_product`, `Size`, `Gender`, `For_child`, `Photo`) VALUES
(1, 'PUMA', 'Ветровка PUMA', '3000', 'Верхняя одежда', '50,52', 'Мужская', 0, 'image.jpg'),
(2, 'O`STIN', 'Брюки O`STIN', '1200', 'Брюки', '44-52', 'Мужская', 0, 'image.jpg'),
(3, 'ZARA', 'Рубашка ZARA', '7000', 'Рубашка', '45-50', 'Мужская', 0, 'image.jpg'),
(4, 'Ден-текстиль', 'Джемпер T Exclusive', '1660', 'Джемпер', '48', 'Мужская', 0, 'image.jpg'),
(5, 'LOVELY HOUZZ', 'Халат LOVELY HOUZZ', '1728', 'Домашная одежда', '42', 'Женская', 0, 'image.jpg');

-- --------------------------------------------------------

--
-- Структура таблицы `opp`
--

CREATE TABLE `opp` (
  `ID` int(11) NOT NULL,
  `Delivery_date` date DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `opp`
--

INSERT INTO `opp` (`ID`, `Delivery_date`, `Address`) VALUES
(1, '2024-06-15', 'Ул. Никифоровская 18'),
(2, '2024-06-24', 'Ул. Дегтярёва 3'),
(3, '2024-06-14', 'Ул. Ладыжская 28'),
(4, '2024-07-01', 'Ул. Укромная 14'),
(5, '2024-06-29', 'Ул. Сеева 16');

-- --------------------------------------------------------

--
-- Структура таблицы `orders`
--

CREATE TABLE `orders` (
  `ID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Units` varchar(255) DEFAULT NULL,
  `Price` decimal(65,0) DEFAULT NULL,
  `Discount` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `orders`
--

INSERT INTO `orders` (`ID`, `Name`, `Units`, `Price`, `Discount`) VALUES
(1, 'Бойцовский клуб', '1', '500', 'Нет'),
(2, 'Ветровка PUMA', '1', '2700', '10%'),
(3, 'Рино-стоп', '2', '222', 'Нет'),
(4, 'Сухой корм Мираторг', '5', '1', 'Нет'),
(5, 'Костюм со встроенной защитой', '1', '8000', '5%');

-- --------------------------------------------------------

--
-- Структура таблицы `pet_products`
--

CREATE TABLE `pet_products` (
  `ID` int(11) NOT NULL,
  `Brand` varchar(255) DEFAULT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Price` decimal(65,0) DEFAULT NULL,
  `Type_of_product` varchar(255) DEFAULT NULL,
  `For_whom` varchar(255) DEFAULT NULL,
  `Photo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `pet_products`
--

INSERT INTO `pet_products` (`ID`, `Brand`, `Name`, `Price`, `Type_of_product`, `For_whom`, `Photo`) VALUES
(1, 'Мираторг', 'Сухой корм Мираторг', '341', 'Корм', 'Для кошек', 'image.jpg'),
(2, 'PURINA', 'Влажный корм felix', '567', 'Корм', 'Для кошек', 'image.jpg'),
(3, 'Happy Jungle', 'Корм для волнистых попугаев сухой', '312', 'Корм', 'Для попугаев', 'image.jpg'),
(4, 'E-COSMETIC', 'ZOORIC шампунь', '200', 'Средство для ухода', 'Для собак', 'image.jpg'),
(5, 'Happy Jungle', 'Корм для хомяков, мышей', '284', 'Корм', 'Для хомяков, мышей и грызунов', 'image.jpg');

-- --------------------------------------------------------

--
-- Структура таблицы `pharmacy`
--

CREATE TABLE `pharmacy` (
  `ID` int(11) NOT NULL,
  `Manufacturer` varchar(255) DEFAULT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Price` decimal(65,0) DEFAULT NULL,
  `Type_of_Product` varchar(255) DEFAULT NULL,
  `License` varchar(255) DEFAULT NULL,
  `Min_Age` varchar(255) DEFAULT NULL,
  `Prescription` varchar(255) DEFAULT NULL,
  `Expiration_date` varchar(255) DEFAULT NULL,
  `Photo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `pharmacy`
--

INSERT INTO `pharmacy` (`ID`, `Manufacturer`, `Name`, `Price`, `Type_of_Product`, `License`, `Min_Age`, `Prescription`, `Expiration_date`, `Photo`) VALUES
(1, 'Валента Фармацевтика', 'Граммидин', '473', 'Таблетки для рассасывания', 'License.pdf', 'с 14 лет', 'Без рецепта', '2 года', 'image.jpg'),
(2, 'Фармстандарт-Лексредства', 'Рино-стоп', '111', 'Капли для носа', 'License.pdf', 'с 6 лет', 'Без рецепта', '2 года', 'image.jpg'),
(3, 'АО «Полисорб»', 'Полисорб', '571', 'Порошок', 'License.pdf', 'С рождения', 'Без рецепта', '5 лет', 'image.jpg'),
(4, 'Урсафарм Арцнаймиттель', 'Хило-Комод', '712', 'Глазные капли', 'License.pdf', 'С рождения', 'Без рецепта', '1096 дней', 'image.jpg'),
(5, 'АО «МПЗ»', 'Себозол', '492', 'Шампунь лечебный', 'License.pdf', 'с 3-х лет', 'Без рецепта', '730 дней', 'image.jpg');

-- --------------------------------------------------------

--
-- Структура таблицы `tourism_fishing_hunting`
--

CREATE TABLE `tourism_fishing_hunting` (
  `ID` int(11) NOT NULL,
  `Brand` varchar(255) DEFAULT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Price` decimal(65,0) DEFAULT NULL,
  `Category` varchar(255) DEFAULT NULL,
  `Photo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `tourism_fishing_hunting`
--

INSERT INTO `tourism_fishing_hunting` (`ID`, `Brand`, `Name`, `Price`, `Category`, `Photo`) VALUES
(1, 'Mikado Princess', 'Удочка маховая', '1157', 'Для рыбалки', 'image.jpg'),
(2, 'Mscooter', 'Палатка туристическая', '2388', 'Туризм и отдых на природе', 'image.jpg'),
(3, 'Военсклад-МСК', 'Костюм со встроенной защитой', '8644', 'Одежды для рыбалки и охоты', 'image.jpg'),
(4, 'Mika', 'Набор блёсен', '446', 'Для рыбалки', 'image.jpg'),
(5, 'Adventure', 'Мощный фонарь', '2635', 'Туризм и отдых на природе', 'image.jpg');

-- --------------------------------------------------------

--
-- Структура таблицы `users_data`
--

CREATE TABLE `users_data` (
  `ID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Date_of_Birth` date DEFAULT NULL,
  `Date_of_Registraction` date DEFAULT NULL,
  `Number_phone` varchar(10) DEFAULT NULL,
  `City` varchar(255) DEFAULT NULL,
  `Home_address` varchar(255) DEFAULT NULL,
  `Ozon_card` varchar(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `users_data`
--

INSERT INTO `users_data` (`ID`, `Name`, `Date_of_Birth`, `Date_of_Registraction`, `Number_phone`, `City`, `Home_address`, `Ozon_card`) VALUES
(1, 'Никифоров Андрей Павлович', '2003-07-10', '2022-04-06', '7980623198', 'Москва', 'Ул. Расковой 12', 'да'),
(2, 'Сидоренко Валерий Никитич', '1995-08-12', '2017-06-23', '7953129095', 'Рязань', 'Ул. Шаболовка 10', 'нет'),
(3, 'Мартынов Владимир Максимович', '2007-10-29', '2023-02-06', '7954234961', 'Челябинск', 'Ул. Чайковского 15', 'нет'),
(4, 'Киселёв Артём Владимирович', '2001-02-20', '2024-05-07', '7985980674', 'Тамбов', 'Ул. Жуковского 8', 'да'),
(5, 'Самойлов Сергей Егорович', '2004-04-20', '2020-08-13', '7980876123', 'Белгород', 'Ул. Тавровская 39', 'да');

-- --------------------------------------------------------

--
-- Структура таблицы `vendor`
--

CREATE TABLE `vendor` (
  `ID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Country` varchar(255) DEFAULT NULL,
  `City` varchar(255) DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `Contact` varchar(255) DEFAULT NULL,
  `Number_phone` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `vendor`
--

INSERT INTO `vendor` (`ID`, `Name`, `Country`, `City`, `Address`, `Contact`, `Number_phone`) VALUES
(1, 'Lime', 'Россия', 'Казань', 'Ул. Носовская 13', 'Антропин Дмитрий Владимирович', '+7-980-549-13-53'),
(2, 'Grandtime', 'Россия', 'Москва', 'Ул. Тверская 7', 'Громов Валерий Сергеевич', '+7-953-421-89-54'),
(3, 'Lek', 'Россия', 'Петропавловск', 'Ул. Сибирская 26', 'Казанин Сергей Яковлевич', '+7-970-133-09-41'),
(4, 'Savana', 'Россия', 'Самара', 'Ул. Дмитриевская 16', 'Миланов Андрей Астольфович', '+7-980-675-43-64'),
(5, 'Geekside', 'Россия', 'Санкт-Петербург', 'Ул. Думская 4', 'Мещеряков Никита Владиславович', '+7-953-348-31-56');

-- --------------------------------------------------------

--
-- Структура таблицы `vendor_products`
--

CREATE TABLE `vendor_products` (
  `ID` int(11) NOT NULL,
  `Category` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `vendor_products`
--

INSERT INTO `vendor_products` (`ID`, `Category`) VALUES
(1, 'Книги'),
(2, 'Одежда'),
(3, 'Аптека'),
(4, 'Туризм, рыбалка и охота'),
(5, 'Еда для животных');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `clothes`
--
ALTER TABLE `clothes`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `opp`
--
ALTER TABLE `opp`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `pet_products`
--
ALTER TABLE `pet_products`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `pharmacy`
--
ALTER TABLE `pharmacy`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `tourism_fishing_hunting`
--
ALTER TABLE `tourism_fishing_hunting`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `users_data`
--
ALTER TABLE `users_data`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `vendor`
--
ALTER TABLE `vendor`
  ADD PRIMARY KEY (`ID`);

--
-- Индексы таблицы `vendor_products`
--
ALTER TABLE `vendor_products`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `books`
--
ALTER TABLE `books`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `clothes`
--
ALTER TABLE `clothes`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `opp`
--
ALTER TABLE `opp`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `orders`
--
ALTER TABLE `orders`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `pet_products`
--
ALTER TABLE `pet_products`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `pharmacy`
--
ALTER TABLE `pharmacy`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `tourism_fishing_hunting`
--
ALTER TABLE `tourism_fishing_hunting`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `users_data`
--
ALTER TABLE `users_data`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `vendor`
--
ALTER TABLE `vendor`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT для таблицы `vendor_products`
--
ALTER TABLE `vendor_products`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `opp`
--
ALTER TABLE `opp`
  ADD CONSTRAINT `opp_ibfk_1` FOREIGN KEY (`ID`) REFERENCES `orders` (`ID`);

--
-- Ограничения внешнего ключа таблицы `orders`
--
ALTER TABLE `orders`
  ADD CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`ID`) REFERENCES `users_data` (`ID`);

--
-- Ограничения внешнего ключа таблицы `vendor`
--
ALTER TABLE `vendor`
  ADD CONSTRAINT `vendor_ibfk_1` FOREIGN KEY (`ID`) REFERENCES `vendor_products` (`ID`);

--
-- Ограничения внешнего ключа таблицы `vendor_products`
--
ALTER TABLE `vendor_products`
  ADD CONSTRAINT `vendor_products_ibfk_1` FOREIGN KEY (`ID`) REFERENCES `orders` (`ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
