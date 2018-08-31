/*
Navicat MySQL Data Transfer

Source Server         : dou
Source Server Version : 80003
Source Host           : localhost:3306
Source Database       : orderingsystem

Target Server Type    : MYSQL
Target Server Version : 80003
File Encoding         : 65001

Date: 2018-08-31 10:01:37
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for menu_item
-- ----------------------------
DROP TABLE IF EXISTS `menu_item`;
CREATE TABLE `menu_item` (
  `menu_id` varchar(32) NOT NULL DEFAULT '',
  `menu_name` varchar(32) DEFAULT NULL,
  `menu_image` varchar(255) DEFAULT NULL,
  `price` float(10,2) DEFAULT NULL,
  `desc` text,
  `type_id` varchar(32) DEFAULT NULL,
  `is_special_price` tinyint(4) DEFAULT NULL,
  `hot_flag` tinyint(4) DEFAULT NULL,
  `new_price` float(10,2) DEFAULT NULL,
  PRIMARY KEY (`menu_id`),
  KEY `type_id` (`type_id`),
  CONSTRAINT `menu_item_ibfk_1` FOREIGN KEY (`type_id`) REFERENCES `menu_type` (`type_id`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of menu_item
-- ----------------------------
INSERT INTO `menu_item` VALUES ('3d0f739716e74352a798fcce0f8d36ee', '猪蹄', 'E:\\OrderingSystem\\OrderingSystem\\icon\\item.png', '50.00', '香辣可口，聊咋咧', '77ebc87ad91e495d8601a7e40766cabf', '1', '1', '25.00');
INSERT INTO `menu_item` VALUES ('3d0f739716e74352a798fcce0f8d36ef', '烤猪蹄', 'E:\\OrderingSystem\\OrderingSystem\\icon\\item.png', '50.00', '香辣可口，聊咋咧', 'e4dc639cdddc4b9c8487e2d8d29905cd', '1', '2', '25.00');

-- ----------------------------
-- Table structure for menu_type
-- ----------------------------
DROP TABLE IF EXISTS `menu_type`;
CREATE TABLE `menu_type` (
  `type_id` varchar(32) NOT NULL,
  `type_name` varchar(32) DEFAULT NULL,
  `image` varchar(50) DEFAULT NULL,
  `sort_index` int(11) DEFAULT NULL,
  `hot_flag` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`type_id`),
  KEY `type_id` (`type_id`,`type_name`,`image`),
  KEY `type_id_2` (`type_id`,`type_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of menu_type
-- ----------------------------
INSERT INTO `menu_type` VALUES ('0358561505684828ad1546196ae37cb4', '酒水', '', '8', '0');
INSERT INTO `menu_type` VALUES ('09718cc059cd47a7a87edfecc49d3904', '主食', '', '6', '0');
INSERT INTO `menu_type` VALUES ('3381b07c9fbe4953b07063182d41f6a3', '热菜', '', '5', '0');
INSERT INTO `menu_type` VALUES ('77ebc87ad91e495d8601a7e40766cabf', '凉菜', '', '4', '0');
INSERT INTO `menu_type` VALUES ('792670b4f004442baaa1323fe39b1e4c', '汤', '', '7', '0');
INSERT INTO `menu_type` VALUES ('87e40a6373b44ddcadd5297304dd62db', '特色', '', '2', '2');
INSERT INTO `menu_type` VALUES ('9069ae504d554c0ca3278c5d8c9b225e', '小吃', '', '3', '0');
INSERT INTO `menu_type` VALUES ('e4dc639cdddc4b9c8487e2d8d29905cd', '推荐', '', '1', '1');

-- ----------------------------
-- Table structure for order_detail_rela
-- ----------------------------
DROP TABLE IF EXISTS `order_detail_rela`;
CREATE TABLE `order_detail_rela` (
  `relaton_id` varchar(32) NOT NULL,
  `count` int(11) DEFAULT NULL,
  `remark` varchar(255) DEFAULT NULL,
  `order_id` varchar(32) DEFAULT NULL,
  `menu_id` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`relaton_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of order_detail_rela
-- ----------------------------

-- ----------------------------
-- Table structure for order_item
-- ----------------------------
DROP TABLE IF EXISTS `order_item`;
CREATE TABLE `order_item` (
  `order_id` varchar(32) NOT NULL,
  `discount` float DEFAULT NULL,
  `offer_count` float DEFAULT NULL,
  `wipe_zero` float DEFAULT NULL,
  `orig_price_count` float DEFAULT NULL,
  `real_price_count` float DEFAULT NULL,
  `table_num` int(11) DEFAULT NULL,
  `remarks` varchar(255) DEFAULT NULL,
  `insert_date` timestamp NULL DEFAULT NULL,
  PRIMARY KEY (`order_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of order_item
-- ----------------------------
