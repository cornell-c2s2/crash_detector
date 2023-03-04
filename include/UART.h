#pragma once

class UART {
  public:

  int port = 0;
  UART() = default;

  void connect();
};