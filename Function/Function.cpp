float Current_angle_calc(float min, float max)
{
    int n = 1; float h = max - min;
    float fb, fa, value1, value2, precision, integral_sum, second_parameter;
    fa = ange_calc(0), fb = ange_calc(t);
    value1 = (fa + fb) * h / 2.0;
    precision = 0.001 + 1;
    while(precision >= 0.001)
    {
        integral_sum = 0.0;
        for(int i = 0; i <= n - 1; i++)
        {
            second_parameter = 0 + (i + 0.5) * h;  // 这里0为积分下限
            integral_sum += ange_calc(second_parameter);
        }
        value2 = (value1 + h * integral_sum) / 2;
        precision = fabs(value1 - value2);
        value1 = value2;
        n *= 2;
        h /= 2.0;
    }
    return value2;
}
