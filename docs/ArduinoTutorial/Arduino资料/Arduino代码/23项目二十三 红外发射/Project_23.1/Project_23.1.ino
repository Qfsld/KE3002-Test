// 引入红外遥控库，用于发送和接收红外信号
#include <IRremote.h>

// 引入SimpleTimer库，用于实现定时器功能（非阻塞式延迟）
#include <SimpleTimer.h>

// 创建一个红外发送对象，使用数字引脚3作为红外信号输出引脚
IRsend irsend_3(3);

// 创建一个SimpleTimer定时器对象
SimpleTimer timer;

// 定时器回调函数：当定时器触发时执行此函数
void Simple_timer_1() {
  // 发送一个32位的RC5红外编码信号，数据值为0x89ABCDEF
  irsend_3.sendRC5(0x89ABCDEF, 32);
}

// 初始化函数，在程序开始时执行一次
void setup() {
  // 设置定时器：每1000毫秒（1秒）触发一次Simple_timer_1函数
  // L后缀表示长整型，确保时间值正确
  timer.setInterval(1000L, Simple_timer_1);
}

// 主循环函数，会重复执行
void loop() {
  // 运行定时器，检查并执行到期的定时任务
  // 这种非阻塞方式允许在等待期间执行其他操作
  timer.run();
}