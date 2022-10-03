/*
* Program：C52 MicroMouse - Virtual Environment.
* Author: YU.J.P
* Time: 2022/10/01 - 2022/10/03
*/

#include <stdio.h>
#include "interface.h"

#define uint unsigned int
#define uchar unsigned char

#define N 8  // 迷宫阶数
extern unsigned int direction;  // 当前小车的方向
extern unsigned int y, x;  // 小车当前位置

/******** TOOL BEGIN ****************************************************************************/

// 显示行走的情况
unsigned char mazeStep[N][N] = {  // infrared[y][x]  横x * 竖y
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}
};

/*
 * 标记当前位置已经走过
 */
void remark(){
    mazeStep[y][x] = 0;
}

/*
* 打印走迷宫实况
*/
void print_step() {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (i == 7 && j == 7) {
                printf(" @ ");
            }
            else if (mazeStep[i][j] == 0) {
                printf(" G ");
            }
            else {
                printf(" # ");
            }
        }
        printf("\n");
    }
}

/******** TOOL END ******************************************************************************/

/******** VIRTUAL BEGIN *************************************************************************/

// 记录迷宫信息
unsigned char maze[N][N] = {  // infrared[y][x]  横x * 竖y
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
    {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}
};//maze

/*
 * 记录迷宫信息
 * 高四位 - 低四位
 */
void recode(){
    printf("# recode():Waiting To Be Perfected...\n");
}

/*
 * 回溯函数 - 回到上一个岔路口
 */
void goBackLast(){
    printf("# goBackLast():Waiting To Be Perfected...\n");
}

/*
 * 走下一步 - 寻路法则
 * 记录岔路口 - 栈实现
 * 实现回溯
 */
void goNext_DFS() {
    // 默认 左手法则 左 -> 前 -> 右 -> 后
    switch (direction) {
        case 0:  // 小车头朝向 上0
            if (get_ir(3) == 0) {
                swerve(10, 0, 90);  // 左转90度
                motor(0, 10, 100);  // 前进
                direction = 3;
                x -= 1;
            }
            else if (get_ir(1) == 0) {
                motor(0, 10, 100);  // 前进
                direction = 0;
                y += 1;
            }
            else if (get_ir(4) == 0) {
                swerve(10, 1, 90);  // 右转90度
                motor(0, 10, 100);  // 前进
                direction = 1;
                x += 1;
            }
            else {
                swerve(10, 0, 180); // 左转180度
                motor(0, 10, 100);  // 前进
                direction = 2;
                y -= 1;
            }
            break;
        case 1:  // 小车头朝向 右1
            if (get_ir(3) == 0) {
                swerve(10, 0, 90);  // 左转90度
                motor(0, 10, 100);  // 前进
                direction = 0;
                y += 1;
            }
            else if (get_ir(1) == 0) {
                motor(0, 10, 100);  // 前进
                direction = 1;
                x += 1;
            }
            else if (get_ir(4) == 0) {
                swerve(10, 1, 90);  // 右转90度
                motor(0, 10, 100);  // 前进
                direction = 2;
                y -= 1;
            }
            else {
                swerve(10, 0, 180); // 左转180度
                motor(0, 10, 100);  // 前进
                direction = 3;
                x -= 1;
            }
            break;
        case 2:  // 小车头朝向 下2
            if (get_ir(3) == 0) {
                swerve(10, 0, 90);  // 左转90度
                motor(0, 10, 100);  // 前进
                direction = 1;
                x += 1;
            }
            else if (get_ir(1) == 0) {
                motor(0, 10, 100);  // 前进
                direction = 2;
                y -= 1;
            }
            else if (get_ir(4) == 0) {
                swerve(10, 1, 90);  // 右转90度
                motor(0, 10, 100);  // 前进
                direction = 3;
                x -= 1;
            }
            else {
                swerve(10, 0, 180); // 左转180度
                motor(0, 10, 100);  // 前进
                direction = 0;
                y += 1;
            }
            break;
        case 3:  // 小车头朝向 左3
            if (get_ir(3) == 0) {
                swerve(10, 0, 90);  // 左转90度
                motor(0, 10, 100);  // 前进
                direction = 2;
                y -= 1;
            }
            else if (get_ir(1) == 0) {
                motor(0, 10, 100);  // 前进
                direction = 3;
                x -= 1;
            }
            else if (get_ir(4) == 0) {
                swerve(10, 1, 90);  // 右转90度
                motor(0, 10, 100);  // 前进
                direction = 0;
                y += 1;
            }
            else {
                swerve(10, 0, 180); // 左转180度
                motor(0, 10, 100);  // 前进
                direction = 1;
                x += 1;
            }
            break;
    }
}

/*
* 模拟遍历迷宫
*/
void coverMaze_DFS() {
    int step = 20;  // 模拟行进步数

    /* 标记当前位置已经走过 */
    remark();
    /* 打印当前行走情况 */
    print_step();
    printf("\n");

    while (step--) {
        /* 蜂鸣器鸣叫 */
        buzzer();
        /* 数码管显示当前位置[y，x] */
        tube(y, x);

        /* 打印小车车头朝向 */
        printf("# Direction:%d,", direction);
        /* 打印红外检测信息 */
        printf("Information:Left=%d, Front=%d, Right=%d\n",
               get_ir(3), get_ir(1), get_ir(4));

        /* 记录迷宫信息 */
        recode();
        /* 走下一步 */
        goNext_DFS();

        /* 标记当前位置已经走过 */
        remark();
        /* 打印当前行走情况 */
        print_step();
        /* 格式打印 */
        printf("\n");
        getchar();  // 回车下一步
    }
}

/******** VIRTUAL END ***************************************************************************/

/******** OPTIMAL BEGIN *************************************************************************/

/* 生成最优路径 */
void create_BFS(){
    printf("# create_BFS():Waiting To Be Perfected...\n");
}

/******** OPTIMAL END ***************************************************************************/

/******** GO BEGIN ******************************************************************************/

/* 最后冲刺 */
void go(){
    printf("# go():Waiting To Be Perfected...\n");
}

/******** GO END ********************************************************************************/

/******** MAIN BEGIN ****************************************************************************/

int main() {
    printf("\tVIRTUAL ENVIRONMENT FOR MICROMOUSE V1.2\n\n");

    /* 遍历迷宫 */
    coverMaze_DFS();

    /* 生成最优路径 */
    create_BFS();

    /* 最后冲刺 */
    go();

    return 0;
}

/******** MAIN END ******************************************************************************/