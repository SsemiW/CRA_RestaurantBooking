#include "gmock/gmock.h"
#include "booking_scheduler.cpp"

TEST(BookingSchedulerTest, 예약은정시에만가능하다정시가아닌경우예약불가) {
	//arrange
	tm notOnTheHour = { 0 };
	notOnTheHour.tm_year = 2021 - 1900; // tm 구조체는1900 년도부터데이터기록
	notOnTheHour.tm_mon = 03 - 1; // tm 구조체는month를0부터관리
	notOnTheHour.tm_mday = 26;
	notOnTheHour.tm_hour = 9; // 9시
	notOnTheHour.tm_min = 5; // 5분, 정각이아님
	notOnTheHour.tm_isdst = -1; // -1 : daylight를자동설정으로맡김
	mktime(&notOnTheHour); // 나머지tm구조체맴버값에대해자동으로계산하여채움
	Customer customer{ "Fake name", "010-1234-5678" };
	Schedule* schedule = new Schedule{ notOnTheHour, 1, customer };
	BookingScheduler bookingScheduler{ 3 };
	//act
	EXPECT_THROW({
	bookingScheduler.addSchedule(schedule);
		}, std::runtime_error);
	//assert
	//expected runtime exception
}

TEST(BookingSchedulerTest, 예약은정시에만가능하다정시인경우예약가능) {
	//arrange
	tm onTheHour = { 0 };
	onTheHour.tm_year = 2021 - 1900;
	onTheHour.tm_mon = 03 - 1;
	onTheHour.tm_mday = 26;
	onTheHour.tm_hour = 9;
	onTheHour.tm_min = 0; // 정각
	onTheHour.tm_isdst = -1;
	mktime(&onTheHour);
	Customer customer{ "Fake name", "010-1234-5678" };
	Schedule* schedule = new Schedule{ onTheHour, 1, customer };
	BookingScheduler bookingScheduler{ 3 };
	//act
	bookingScheduler.addSchedule(schedule);
	//assert
	EXPECT_EQ(true, bookingScheduler.hasSchedule(schedule));
}

TEST(BookingSchedulerTest, 시간대별인원제한이있다같은시간대에Capacity초과할경우예외발생) {

}

TEST(BookingSchedulerTest, 시간대별인원제한이있다같은시간대가다르면Capacity차있어도스케쥴추가성공) {

}

TEST(BookingSchedulerTest, 예약완료시SMS는무조건발송) {

}

TEST(BookingSchedulerTest, 이메일이없는경우에는이메일미발송) {

}

TEST(BookingSchedulerTest, 이메일이있는경우에는이메일발송) {

}

TEST(BookingSchedulerTest, 현재날짜가일요일인경우예약불가예외처리) {

}

TEST(BookingSchedulerTest, 현재날짜가일요일이아닌경우예약가능) {

}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}