
pot_mean = mean(potentiometer)
pot_median = median(potentiometer)
pot_mode = mode(potentiometer)
pot_SD = std(potentiometer)

temp_mean = mean(temperature)
temp_median = median(temperature)
temp_mode = mode(temperature)
temp_SD = std(temperature)

light_mean = mean(light1)
light_median = median(light1)
light_mode = mode(light1)
light_SD = std(light1)

count_sw0 = sum(switch0 == 0)
count_sw1 = sum(switch1 == 0)
count_sw2 = sum(switch2 == 0)
count_sw3 = sum(switch3 == 0)

subplot(2,1,1)
plot(time,potentiometer,time,temperature,time,light1)

xlabel('Time (ms)')
ylabel('Data')
title('Potentiometer, Temperature, and Light Data over Time')
grid on
hold on
A = polyfit(time,potentiometer,1)
linearY1 = time*A(1)+A(2)
plot(time, linearY1, '--','LineWidth',2)


B = polyfit(time,temperature,1)
linearY2 = time*B(1)+B(2)
plot(time, linearY2, ':','LineWidth',2)

C = polyfit(time,light1,1)
linearY3 = time*C(1)+C(2)
plot(time, linearY3, '-.','LineWidth',2)
legend('Potentiometer','Temperature','Light','Pot. Fit Line','Temp. Fit Line','Light Fit Line')
subplot(2,1,2)
bar_plot = [count_sw0 count_sw1 count_sw2 count_sw3]
bar(bar_plot)
set(gca,'XTickLabel',{'Switch 0', 'Switch 1', 'Switch 2', 'Switch 3'}) % gca = get current axes
title('Number of Times Each Switch Was Pressed')
xlabel('Switch number')
ylabel('# of Times Pressed')