#pragma once

namespace DriveConstants {
    constexpr int kLeftMotor1Port = 0;
    constexpr int kLeftMotor2Port = 3;
    constexpr int kRightMotor1Port = 2;
    constexpr int kRightMotor2Port = 1;
}

namespace OIConstants {
    constexpr int kDriverControllerPort = 2;
}

namespace ShooterConstants {
    constexpr int MaxRPM = 5700,
                  ShootConst = 5000;

    const double kP = 6e-5, 
                 kI = 1e-6,
                 kD = 0, 
                 kIz = 0, 
                 kFF = 0.000015, 
                 kMaxOutput = 1.0, 
                 kMinOutput = -1.0;
}