1.	Balanced Symbols
a. Đặt vấn đề
Trong trình soạn thảo các ngôn ngữ lập trình, khi chúng ta viết code, thường sử dụng ( ) [ ] { }. Trình biên soạn luôn luôn check để đảm bảo với một symbol ( luôn tìm được symbol ) tương ứng - tương tự với cặp symbol [ ] và { }. Vấn đề này được gọi là "các biểu tượng cân bằng".
b. Hãy bắt đầu bài toán với một chuỗi các dấu ngoặc đơn. Hãy viết chương trình kiểm tra xem chuỗi có cân bằng hay không. Để giải quyết bài toán này chúng ta có thể quan sát thấy rằng, trong một chuỗi các ngoặc đơn nhìn từ trái qua phải, dấu ngoặc mở đầu tiên phải khớp với dấu ngoặc đóng cuối cùng. Các ngoặc đóng sẽ khớp với các ngoặc mở theo thứ tự đảo ngược của sự xuất hiện.

Do đó có thể dùng ngăn xếp để giải quyết bài toán này.
c. Hãy mở rộng chương trình với một đoạn code bất kì của ngôn ngữ lập trình C/C++. Hãy check xem các symbols trong đoạn code có cân bằng hay không. Nếu không hãy báo lỗi. (Mô phỏng lại hoạt động check syntax của các trình soạn thảo).
d. Hãy mở rộng chương trình với việc check cân bằng của các thẻ html. Ví dụ đoạn code html sau:
 
Với mỗi thẻ mở <...> luôn có một thẻ đóng tương ứng </...>. Hãy viết chương trình check syntax của một đoạn code html. Chú ý rằng một số thẻ như <p>, <br> không có thẻ đóng. Hãy test với những đoạn dữ liệu lớn để xem hiệu năng của chương trình.
2.	Ý tưởng giải thuật cân bằng dấu ngoặc
- File văn bản đưa vào được khai báo là 1 mảng xâu các ký tự
-Khởi tạo 1 mảng 2 chiều xác định các ký tự là ngoặc tương ứng của nhau:
 char [][] Terms = { {‘(’ , ’)’ }; { ‘[’ , ’]’ } ; { ‘{’ , ’}’ } };
a. Xây dựng 1 hàm xác định xem ký tự đưa vào có phải là dấu mở ngoặc hoặc đóng ngoặc hay không ?
 bool isTerm( char c ){

}
b. Xây dựng 1 hàm xác định xem ký tự đưa vào có phải là dấu mở ngoặc hay không ?
bool  isOpenTerm( char c ){
	//Duyệt tử đầu tới cuối mảng xâu ký tự
	// Kiểm tra ký tự nhập vào có phải là dấu mở ngoặc không
	// Nếu đúng trả về true
	// Nếu sai trả về false
}
c. Xây dựng 1 hàm kiểm tra xem hai ký tự đưa vào có phải là 1 cặp ngoặc tương ứng của nhau đã được định nghĩa trong mảng Terms hay không ?
 bool matches ( char x, char y ){
	// Kiểm tra 2 ký tự đưa vào có phải là cặp ngoặc tương ứng của nhau hay không
	// Nếu đúng trả về true
	// Nếu sai trả về false
}
d. Xây dựng hàm mục tiêu kiểm tra xem mảng xâu đưa vào cân bằng ngoặc hay không ?
bool isBalanced( char xau ){
	+ Khởi tạo 1 stack
	+ Duyệt từ đầu tới cuối xâu đưa vào từng ký tự một
	+ Kiểm tra xem ký tự đó có phải là dấu ngoặc hay không bằng hàm isTerm()
+ Kiểm tra xem ký tự đó có phải dấu mở ngoặc hay không bằng hàm         isOpenTerm()
Nếu đúng thì đẩy nó vào stack
	Nếu sai thì tức là ký tự đưa vào là dấu đóng ngoặc, ta tiến hành kiểm tra ký tự đó và ký tự được lấy ra ở đỉnh stack bằng hàm top() (định nghĩa bởi stack) xem có phải là 1 cặp ngoặc tương ứng của nhau hay không thông qua hàm matches(x, y).
	Đến đây có 2 trường hợp xảy ra:
•	Nếu không trùng thì hàm matches() trả về false luôn
•	Nếu hàm matches trả về true thì loại bỏ phần tử ở đỉnh ngăn xếp ra khỏi ngăn xếp và tiếp tục duyệt vòng lặp tới ký tự cuối cùng
Ra khỏi vòng lặp, ta kiểm tra xem stack có rỗng không bằng hàm isEmptyStack() (định nghĩa bởi stack) . Nếu stack rỗng thì nghĩa là xâu nhập vào cân bằng ngoặc (hàm matches() trả về true ) và stack không rỗng thì xâu nhập vào không cân bằng ngoặc (hàm matches() trả về false ).
}
-	Việc kiểm tra sự cân bằng của thẻ HTML ta làm tương tự tuy nhiên có một số sai khác:
•	Đầu tiên là thay vì khai báo 1 mảng 2 chiều định nghĩa các cặp ngoặc tương ứng thì ta phải khai báo 2 mảng 1 chiều khác nhau, một lưu các thẻ mở HTML và một lưu các thẻ đóng tương ứng, theo đúng thứ tự.
•	Thứ hai là viết 2 hàm, một trong đó đọc các ký tự trong file đầu vào và lưu tất cả các ký tự đó vào một mảng một chiều. Hàm thứ 2 đọc từng từ một (trích xuất ra từng từ một ) từ mảng ký tự lấy ra được từ hàm thứ nhất.
•	Xây dựng được 1 stack trong đó trường dữ liệu là một chuỗi các ký tự (mảng char ) chứ không đơn thuần là 1 ký tự như trong trường hợp trên.
•	Các hàm kiểm tra có phải là thẻ HTML hay không, có phải thẻ mở, thẻ đóng HTML hay không, hay có cân bằng thẻ HTML hay không cũng phải được xây dựng lại.

