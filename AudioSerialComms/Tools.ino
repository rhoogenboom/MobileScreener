int BitShiftCombine(byte x_high, byte x_low)
{
  int combined;
  combined = x_high;
  combined = combined << 8;
  combined |= x_low;
  return combined;
}

byte BitShiftGetHigh(int combined)
{
  return (combined >> 8);
}

int BitShiftGetLow(int combined)
{
  int intermediate = combined << 8;
  return (intermediate >> 8);
}

