#include "../inc/bellman.h"

    void BF(int G[30][30], int numberOfVertices, char startVertex, int Label[30],int Prev[30]){

        int start = startVertex - 'A';
        //Nếu đỉnh bắt đầu là chưa có thì set các giá trị Label = khoảng cách từ đỉnh bắt đầu đến đỉnh thứ i
        if (Label[start] == -1){
            for (int i = 0; i < numberOfVertices; i++){
                Label[i]= G[start][i];
                Prev[i] = start;
//Nếu đỉnh thứ i bằng 0 => không có đường đi tới. Ta đặt lại là -1 để k bị lẫn với đỉnh tự đi đến chính nó, Prev bằng -1 để nhận biết đỉnh trước nó không tồn tại
                if (Label[i]== 0){
                    Label[i] = -1;
                    Prev[i] = -1;
                }
            }
            //Sau khi set các giá trị Label xong hết rồi thì set Label của điểm bắt đầu là 0; và trước đỉnh bắt đầu k có đỉnh nào nên set lại là -1.
            Label[start]= 0;
            Prev[start]= -1;
            return;
        }
        //lưu các giá trị Label vào biến temp để không bị thay đổi Label trong lúc tính
        int temp[30];
        for (int i = 0 ;i< numberOfVertices; i++){
            temp[i]= Label[i];
        }
        //Vòng lặp 1 kiểm tra xem có phải là đỉnh không tới được k. Nếu k tới được thì set giá trị lớn (như lúc làm tự luận)
        for(int u = 0; u < numberOfVertices; u++){
            if (temp[u] == -1 && Label[u] == -1){
                Label[u] = 999;
                Prev[u] = 0;
                temp[u] = 999;
            }
            //Nếu Vòng lặp chạy tới đỉnh bắt đầu thì skip không có cập nhật (điều kiện tương đương của if này là u != start && Label[u] == 0) thì chạy lệnh for
            if (u == start || Label[u] != 0)// nếu if (true => do nothing; False thì bỏ qua câu lệnh)
            for(int v=0; v < numberOfVertices; v++){
                if((temp[v] + G[v][u]) < Label[u] && temp[v] != -1 && G[v][u] != 0){
                    Label[u] = temp[v] + G[v][u];
                    Prev[u] = v;
                }
            }
        }
        //nãy tất cả các giá trị mà k tới được thì ta set là 999 (coi như là vô cùng) mà đề bài dã sure là không có giá trị âm nên ta thế -1
        for (int i = 0; i< numberOfVertices; i++){
            if (Label[i] == 999){
                Label[i] = -1;
                Prev[i] = -1;
            }
        }
    }

    string BF_Path(int G[30][30], int numberOfVertices, char startVertex,char goalVertex){
       int path[30];
       string result;
       int pathLength = 0;
       int at = goalVertex - 'A';
       int Label[30];
       int Prev[30];
       //Khỏi tạo Label và Prev
       for (int i = 0 ; i < numberOfVertices; i++){
        Label[i] = -1;
        Prev[i] = -1;
       }
       //đưa BF vào vòng For chạy từ đỉnh thứ 1 tới lần V -1 để lấy các giá trị Prev, Label
       for (int i = 0; i < numberOfVertices - 1; i++){
        BF(G, numberOfVertices, startVertex, Label, Prev);
       }
       //at là điểm kết thúc của Prev được chuyển hóa thành dạng số
       while (at != -1) {//Nếu at khác -1 vì trong hàm trên ta đã có lệnh nếu đó là đỉnh bắt đầu thì Prev là -1 nên ta cứ trruy hồi at miễn sao k bằng -1 thì chứ truy lên tới đỉnh bắt đầu thì thoát khỏi vaongf lặp
            path[pathLength++] = at;
            at = Prev[at];  // Truy ngược về đỉnh tiền nhiệm
        }
       // Kiểm tra xem đường đi có tồn tại không Nếu giá trị path cuối cùng k phải là giá trị khỏi đầu => không hợp lệ
        if (path[pathLength - 1] != startVertex - 'A') {
            return "No path exists";
        }

        //viết ngược lại path
        
        for (int i = pathLength - 1; i >= 0; i--) {
            result += char(path[i] + 'A');
            if (i > 0) result += " ";
           
        }
        return result;
    }