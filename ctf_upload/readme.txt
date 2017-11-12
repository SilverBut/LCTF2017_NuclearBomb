题目名称：
	NuclearBomb
题目描述：
	当上了一国统领，手里总是要多点东西，比如https://item.taobao.com/item.htm?id=537823795903。你看，一般人买不起吧；）
	（注意，你得到的flag里不包含LCTF{}）
题目Flag：
	LCTF{cuda_15_fun_bu7_d0_u_kn0w_h0w_to_make_FUN_by_it_nowadays}
难度：
	三星
部署注意：
	1. 严格按照以下方法部署
		a. 获得代码库后，cd到代码库根目录
		b. 修改CMakeLists.txt，将含有"SOLVE_FLAG"的一行**取消注释**
		c. 执行： cmake . && make && ./out/nuclear_bomb > ./src/flag_table.hpp
		d. 将上面的一行取消注释
		e. 执行： cmake . && make
		f. 目前./out/nuclear_bomb就是题目文件（未strip）
	2. 题目理论爆破时间需要10小时（i7-4712MQ，8线程，C++，未开优化），因此尽量在比赛结束10小时前放出
	3. Hint：https://en.wikipedia.org/wiki/Mersenne_Twister
题目Writeup：
	http://github.com/SilverBut/LCTF2017_NuclearBomb
	（私有Repo，比赛结束后开放）
争议解决：
	直接联系出题人
