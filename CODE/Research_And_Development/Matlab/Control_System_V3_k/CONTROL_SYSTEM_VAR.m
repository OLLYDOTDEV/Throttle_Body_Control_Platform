% Foot Pedal Setting
Desire_Max = 255;
Desire_Min = 0;
Old_Max = 3.3;
Old_Min = 0;

% H-Bridge Setting
EN_Pin = 0;
Direction_Pin = 1;

% PID Setting
Kp = 1.4;
Ki = 4;
Kd = 2;
Kn = 0.1;

% System Setting
B_aet=0.1503;
J_aet=0.0035;
roa=0.24;
theta_o=12;
K_sp=0.0914;
Toa_ho=0.3193;
F_so=0.089;

% Control Setting
Omega_o=5;
Beta1=3*Omega_o;
Beta2=3*(Omega_o^2);
Beta3=(Omega_o^3);
omga_c=10;




range = 200:1000;
x = linspace(0, 10, length(range));

plot(x, Signal(range));
hold on;
plot(x, PID1(range), 'LineWidth', 1);  
plot(x, Propotional1(range),'LineWidth', 1);     
hold off;

title('Throttle Body Feedback VS. Foot Pedal Signal')
ylabel('Signal Value')
xlabel('Time (Second)')
legend('Signal', 'PID','Propotional')
axis padded
xticks(0:1:10)
yticks(0:10:100)



