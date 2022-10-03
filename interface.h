//
// Created by YU.J.P on 2022/10/3.
//


#ifndef MY_VM_INTERFACE_H
#define MY_VM_INTERFACE_H

/*
* 蜂鸣器鸣响
*/
void buzzer();

/*
* 数码管驱动
* param y, x : 数码管显示的数字
*/
void tube(int y, int x);

/*
* 电机驱动 - 行进函数
* param direction : 小车行进方向 0：前，1：后
* param speed : 小车行进速度
* param distance : 小车行进的距离
*/
void motor(int direction, int speed, int distance);

/*
* 电机驱动 - 转向函数
* param direction : 小车转向方向 0：左，1：右
* param speed : 小车转向速度
* param degree : 小车转向角度
*/
void swerve(int speed, int direction, int degree);

/*
 * param num :对应组号的红外信息
 * left, front, right - 3 1 4
 * */
unsigned int get_ir(int num);

#endif //MY_VM_INTERFACE_H
