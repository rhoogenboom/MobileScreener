int SetSpeed(int stopValue, int turnValue, bool reverse) {
  if (reverse) {
    return stopValue - turnValue;
  } else {
    return stopValue + turnValue;
  }
}

