#include <cv_bridge/cv_bridge.h>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <opencv2/opencv.hpp>

using std::placeholders::_1;

class ImageModifierNode : public rclcpp::Node
{
public:
  ImageModifierNode() : Node("src_get")
  {
    image_subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/image_raw", 10, std::bind(&ImageModifierNode::imageCallback, this, _1));
  }
  cv::Mat src_;

private:
  void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
  {
    // try
    // {
    // 将ros图像消息转为opencv图像
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    // clone原始图像
    cv::Mat modified_image = cv_ptr->image.clone();
    //修改图像
    cv::Mat image(msg->height, msg->width, CV_8UC3, msg->data.data());
    cv::imshow("get", image);
    // cv::imshow("get", modified_image);
    cv::waitKey(10);
    // src_ = modified_image.clone();
    // cv_bridge::CvImage modified_cv_img(cv_ptr->header, cv_ptr->encoding, cv_ptr->image);
    // sensor_msgs::msg::Image::SharedPtr modified_image_msg = modified_cv_img.toImageMsg();

    // //发布修改后的图像
    // modified_image_publisher_->publish(*modified_image_msg);
    // }
    // catch (cv_bridge::Exception& e)
    // {
    //   RCLCPP_ERROR(this->get_logger(), "cv_bridge exceotion: %s", e.what());
    // }
  }
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr modified_image_publisher_;
};

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ImageModifierNode>());
  ImageModifierNode img;
  while (1)
  {
    cv::imshow("src", img.src_);
    cv::waitKey(0);
  }

  rclcpp::shutdown();
  return 0;
}
