#include <iomanip>
#include <iostream>

bool leap_year(int year);
size_t days_in_month(int month_number, bool is_leap);

int main() {
  size_t day_width{7};
  size_t months_year{12};
  size_t max_weeks{6};
  size_t day_in_month{0};
  size_t year{};
  std::string week[7]{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
  size_t week_length{7};

  std::string months[12]{"January",   "February", "March",    "April",
                         "May",       "June",     "July",     "August",
                         "September", "October",  "November", "December"};
  size_t day{};
  std::cout << "Enter a year : ";
  std::cin >> year;
  std::cout << "Enter the first day of the year [1: Monday ... 7: Sunday] : ";
  std::cin >> day;
  --day;
  bool leap{leap_year(year)};
  size_t current_day{0};

  for (size_t month{}; month < months_year; ++month) {
    std::cout << "-- " << months[month] << " " << year << " --" << std::endl;
    day_in_month = days_in_month(month, leap);

    if (month == 0) {
      current_day = day;
    }
    size_t today{1};
    for (std::string day : week) {
      std::cout << std::setw(day_width) << day;
    }
    std::cout << std::endl;
    for (size_t week{0}; week < max_weeks; ++week) {
      for (size_t day{0}; day < week_length; ++day) {

        if (day >= current_day) {
          std::cout << std::setw(day_width) << today++;
          if (today > day_in_month) {
            week = 6;
            current_day = (day == 6) ? 0 : day + 1;
            break;
          }
          current_day = 0;
        } else {
          std::cout << std::setw(day_width) << " ";
        }
      }
      std::cout << std::endl;
    }
  }
}

bool leap_year(int year) {
  bool leap{false};
  if ((year % 100 == 0) && (year % 400 == 0)) {
    leap = true;
  } else if ((year % 4 == 0) && (year % 100 == 0)) {
    leap = false;
  } else if (year % 4 == 0) {
    leap = true;
  }
  return leap;
}

size_t days_in_month(int month_number, bool is_leap) {
  size_t days_in_month{};
  if (month_number == 0 || month_number == 2 || month_number == 4 ||
      month_number == 6 || month_number == 7 || month_number == 9 ||
      month_number == 11) {
    days_in_month = 31;
  } else if (month_number == 1 && is_leap) {
    days_in_month = 29;
  } else if (month_number == 1) {
    days_in_month = 28;
  } else {
    days_in_month = 30;
  }
  return days_in_month;
}
