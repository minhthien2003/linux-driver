# linux-driver
build kernel modul:

make -c ~/(kernel version) M='pwm' modules

linux kernel module
b1: Viết mã nguồn (File hello_kernel_module.c)
Bước 2. Viết Makefile cho kernel module để biên dịch (đặt cùng thư mục file mã nguồn)
Bước 3. Biên dịch bằng lệnh make được file hello_kernel_module.ko

Bước 4. Cài đặt module vào hệ thống (sử dụng lệnh insmod) 

insmod  hello_kernel_module .ko

           Gỡ kernel module dùng lệnh rmmod

Bước 5. Kiểm tra quá trình cài đặt xem module đã cài đặt thành công hay chưa

(Trên Ubuntu, mở System/Log Viewer xem mục kernel log)

2.2. Viết một device driver đơn giản

Bước 1: Xây dựng device driver đơn giản theo cơ chế kernel module

- Viết mã nguồn (File hello_driver.c) theo đúng khuôn dạng qui định
- Bước 2. Viết Makefile để biên dịch mã nguồn trên, được file hello_driver.ko
- Bước 3: Cài đặt device driver theo cơ chế của Kernel module

Lệnh:     insmod hello_driver.ko

Bước 4: Sử dụng lệnh mknod để tạo ra một device file trong thư mục /dev (giả sử đặt tên device file là KTMT0)

              mknod /dev/KTMT0 c 250 1

(Tạo ra một device file có tên là KTMT0 cho device driver kiểu character có major id là 250)

(Xem major id của kernel module hello_driver dùng lệnh cat /proc/devices)

Đến đây, chúng ta có một thiết bị tên KTMT0 với driver đã viết (cung cấp hàm read). Bước tiếp theo sẽ viết một ứng dụng để giao tiếp thiết bị này.

Bước 5: Viết chương trình để test giao tiếp với driver (hello_driver)
