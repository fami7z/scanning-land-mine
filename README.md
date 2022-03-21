# scanning-land-mine
二维数组应用-扫雷小游戏
1. 随机数产生方法
  （1）由时间戳，获取电脑当前时间，产生随机数
  （2）srand((unsigned int) time(NULL));
  （3）// 生成随机的下标
      int x = rand() % row +1;
      int y = rand() % col +1;
2. int 转 char 方法
  int count = GetMineCount(mine, x, y);
  show[x][y] = count + '0';   //参考ASCII码表：‘0’ -- 48 ； ‘1’ -- 49 ； ‘2’ -- 50
3. static 用法
// 加上static，使该函数只在game.c中可见，不会产生冲突。
// static 作用：
// 1. 修饰局部变量
// 2. 修饰全局变量
// 3. 修饰函数
      static int GetMineCount(char mine[ROWS][COLS], int x, int y)
