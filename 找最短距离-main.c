//
//  main.c
//  czstr
//
//  Created by 郭有超 on 2018/7/31.
//  Copyright © 2018年 郭有超. All rights reserved.
//

#include <stdio.h>
#include <string.h>

// 寻找字符串中每个字符到给定字符之间的最短距离。
int* findMin(char * str, char c){
    // 字符串长度
    int strSize = strlen(str);
    int canfind = 1;
    int tCharD = c;
    if (strSize < 1 || strSize > 1000 || c == NULL || tCharD < 97 ){
        canfind = 0;
    }
    // 判断给定的字符串是否超出比较的范围
    if(canfind == 1){
        // 找到的最短路径数据数组
        int allLenght[strSize];
        // 存储给定字符在字符串中的位置下标
        int allFind[strSize];
        // 初始化相关数组的初始值
        for (int i = 0; i < strSize; i ++) {
            allLenght[i] = 0;
            allFind[i] = 0;
        }
        // 当前存储位置的下标值
        int allCountStartindex = 0;
        // 逻辑开关
        int curfindIndex = 0;
        for (int abcIndex = 0; abcIndex < strSize; abcIndex ++) {
            if (str[abcIndex] == c){
                // 前后对比
                if(allFind[allCountStartindex - 1] != 0){
                    int czCount = abcIndex - allFind[allCountStartindex - 1];
                    int czPart  = (czCount - 1) / 2;
                    for(int tIndex = allFind[allCountStartindex - 1] + 1; tIndex <= allFind[allCountStartindex - 1] + czPart; tIndex ++){
                        allLenght[tIndex] = -(allLenght[tIndex] - czCount);
                    }
                }
                curfindIndex = abcIndex + 1;
                allFind[allCountStartindex] = abcIndex;
                allCountStartindex = allCountStartindex + 1;
                allLenght[abcIndex] = 0;
            }else{
                for(int j = curfindIndex;j<= abcIndex; j++){
                    allLenght[j] = allLenght[j] + 1;
                }
                // 判断是否为最后一次查找 是的话将后续的字符往前找
                if(abcIndex == strSize - 1){
                    int czCount = strSize - allFind[allCountStartindex - 1];
                    for(int tIndex = allFind[allCountStartindex - 1] + 1; tIndex <= allFind[allCountStartindex -1] + czCount; tIndex ++){
                        allLenght[tIndex] = -(allLenght[tIndex] - czCount);
                    }
                }
            }
        }
        
        // 打印找到的数据
        printf("\n\n[");
        for (int i = 0; i < strSize; i ++) {
            if(i == strSize - 1){
                printf("%d",allLenght[i]);
            }else{
                printf("%d,",allLenght[i]);
            }
        }
        printf("] \n\n");
        return allLenght;
    }else{
        printf("参数错误，不能查找哦! \n");
        return NULL;
    }
}

int main(int argc, const char * argv[]) {
    char * abc = "joycastleisnotacastle";
    char c = 't'; // NULL;
    int *findMinPath = findMin(abc, c);
    return 0;
}
