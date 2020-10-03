# RollerCoaster

台灣科技大學 電腦圖學導論 第三份作業

[demo影片](https://drive.google.com/file/d/1Kx_Y2XqrozUA6wt2mx7D4-15F3PLcBYl/view?fbclid=IwAR20nS_vJieOBD4ZKMDvC_ynNW9LZOEw-t20SxXNeFgZsxUyKFu2OxNXeyM)

## 技術介紹
### skybox
* 畫一個圓包住整個環境
* 再利用shader貼上skybox的貼圖
* skybox下載網址：http://www.custommapmakers.org/skyboxes.php
### 水波
* 使用shader來達成反射、折射和光線變化，Texture是使用背景的SkyBox
* 使用網路上的stb_image來載入Cube圖片
* 使用sin波來計算水波的起伏
### 石頭
* 使用shader來達成光線變化
* 使用sin波來計算山波的起伏
### 山丘
* 使用shader來達成光線變化
* 使用sin波來計算石頭的型變
### 軌道繪製 (直線/曲線)
* 依此PPT製作: http://dgmm.csie.ntust.edu.tw/?uid=5e1d29d5654bd
* 記錄前一次畫的點
* 畫前一次到此次的點的線
### 木條
* 當經過固定間隔距離時，先記錄軌道開始的位置
* 再經過木條長度後，畫上木條
* 重複做到繞完一圈為止
### 煙火
* 使用粒子特效完成
* 當耗盡時間以後會爆炸
* 隨機選擇爆炸效果
### 隧道
* 使用shader來達成光線變化
* 使用sin的幅度當作頂
### 等速行駛
* 定義點的距離 = 2
* 以直線/曲線的細微分段做疊加，累加超過點距離時，將當前點加入路徑點
* t_time(行駛進度) 每幀增加 速度(Points per frame)/路徑點總數 
* Index = 路徑點總數 * t_time 
* 位置 = 路徑點\[ Index \]
### 火車頭
* 行進方向 = 下一個位置-當前位置 (斜率)
* 側翻 : 使用車頂方向與行進方向算出角度並旋轉
### 車廂 
* 車廂位置 = 路徑點\[ 火車頭位置Index - 10*車廂號碼 \]
* 方向.側翻同火車頭
### 人
* 根據車廂位置.方向.側翻放置
* 可調整每個車廂上人的位置，不會超出車廂
### Load .obj 3D Model 
* 原始Code: http://dgmm.csie.ntust.edu.tw/?uid=5e1d29d56a47a
* 加入位置.位移(人)及角度改變，並使其繪製在正確位置
### 建築物
* 個別設定好位置.方向後不再移動
### 視角
* #### World
    * (0.2,0.4,0)的位置有Arcball，可右鍵旋轉移動camera位置
* #### Top
    * 固定的camera由上往下(0,0,0)看
* #### Train
    * camera在車頭位置往行駛方向看，此時車頭不render
* #### Human
    * 可調整camera要在哪個人身上
    * camera在人的位置往正前方看，此時此人不render
### BGM
* 使用 [QMediaPlayer](https://docs.huihoo.com/qt/5.4/qmediaplayer.html) & [QMediaPlaylist](https://docs.huihoo.com/qt/5.4/qmediaplaylist.html) 播放
* BGM URL: https://www.youtube.com/watch?v=Uz7xMZ5YyGY
## Reference
1. 圖學課程資源: http://dgmm.csie.ntust.edu.tw/?ac1=courdetail_CG2012F&id=5cf1e97b68aa9
2. QT: https://docs.huihoo.com/qt/5.4/
3. Model下載: https://free3d.com/3d-models/obj
