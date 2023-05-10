----------------------$ **_CARO GAME_** $-------------------------

**Tổng quan**
-
- Game Caro với chế độ hai người chơi và có thể chỉnh bản cờ theo kích thước mà bạn muốn.
- Hướng dẫn chỉnh kích thước : ![image](https://github.com/quyk67uet/Caro_Game.MQ/assets/125531081/56bc9ee3-cd05-4809-b2fa-ab3a710fadc3)
- Ở phần NUM_BOX_OF_EDGE trong header file (Constants.h) bạn có thể điền kích cỡ mình chọn tùy ý ( ví dụ : 12x12).

**Luật chơi**
-
- Game có 2 người chơi, người đi trước là X(Player1), người đi sau là O(Player2), chơi luân phiên nhau.
- Nếu có 5 dấu (X/O) trên 1 hàng ngang, hàng dọc hoặc đường chéo thì người chơi (X/O) sẽ chiến thắng.
- Nếu đã đánh hết cả bàn cờ mà không tìm ra được người thắng, thì game sẽ cho kết quả hòa.

**Cách chơi**
-
- Nhấn vào nút Start trên Menu để bắt đầu, di chuyển chuột và bấm chọn các ô trên màn hình.
- Khi đã có người thắng hoặc hòa, chọn Play Again để chơi lại, Menu hoặc Exit để thoát.

**Hướng dẫn cài đặt**
-
- **B1** : Ấn Download Zip để tải file về và giải nén trong thư mục của bạn.![image](https://github.com/quyk67uet/Caro_Game.MQ/assets/125531081/fb6814a8-a654-4fb7-92fe-42a4e156f93f).

- **B2** : Tải phần mềm Code Block (20.03 ). Link download :(https://sourceforge.net/projects/codeblocks/).

- **B3** : Tải các thư viện liên kết : 

 SDL2

 SDL2_image

 SDL2_ttf

 SDL2_mixer
 
 - **B4** : Lên mạng xem cách cài SDL2 trên Code Block .
 
 - **B5** :Sau khi cài xong, bạn tạo một project trên code block. Rồi add các header file(có đuôi.h) và sources file(có đuôi.cpp) vào project của bạn. Ấn debug và bắt đầu play.
 
 **_Cảm ơn và chúc bạn chơi game vui vẻ_**.
