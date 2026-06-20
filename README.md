# 🌬️ Environmental Dust Density Data Acquisition System

An Arduino-based data acquisition and signal processing system engineered to analyze the spatial and temporal variance of airborne particulate matter (dust) across diverse indoor and outdoor micro-environments. 

Developed as an academic study for the Data Acquisition Laboratory, this project goes beyond simple sensor integration by employing custom hardware stabilization, digital signal filtering, and rigorous statistical analysis to quantify how airflow, thermodynamics, and human activity influence air quality.

## ⚙️ How It Works
The system utilizes a light-scattering optical dust sensor. An infrared LED illuminates airborne particles, and a photodiode measures the scattered light intensity. The Arduino Nano processes this analog signal, applies a median filter to strip environmental electrical noise, and maps the output to a physical dust density (mg/m³) using an empirically derived transfer function.

## 🛠️ Hardware & Tech Stack

### Components
* **Microcontroller:** Arduino Nano
* **Sensor:** SHARP GP2Y1010AU0F Optical Dust Sensor
* **Signal Stabilization:** Custom 150Ω resistor and 220μF capacitor network to stabilize the sensor's internal LED current.

### Software
* **Firmware:** C++ (Arduino)
* **Data Processing:** Median Filtering Algorithm 
* **Analysis:** Python / Data Visualization Libraries (for temporal graphing and statistical modeling)

## 📊 Key Analytical Findings
By deploying this unit across multiple university environments (laboratories, lobbies, and outdoor grounds), the data revealed distinct thermodynamic behaviors:
* **Indoor Accumulation:** Enclosed spaces suffer from activity-driven dust accumulation. Stagnant air and human movement continuously trap and resuspend particulates throughout the afternoon.
* **Outdoor Dispersion:** Outdoor environments benefit from natural air purification. As ground temperatures rise, thermal convective currents dynamically disperse particulate matter into higher atmospheric layers.
* **Statistical Validity:** The filtered data maintained an exceptionally low standard deviation (0.0063 mg/m³) and realistic positive skewness, confirming the sensor accurately tracked stable baselines alongside transient physical dust spikes.

## 🚀 Setup & Execution
1.  Assemble the hardware circuit, ensuring the 150Ω resistor and 220μF capacitor are correctly placed between the sensor's V-LED line and the Arduino's 5V/GND.
2.  Clone the repository: `git clone https://github.com/Thilanka-Dissanayake/Dust-Density-Data-Acquisition.git`
3.  Open the source code located in `/Firmware` in the Arduino IDE.
4.  Verify the empirical calibration constants (`voc = 0.38`, `K = 0.17`).
5.  Flash the firmware to the Arduino Nano.
6.  Monitor the live `mg/m3` particulate readings via the Serial Monitor (9600 baud).

## 📄 Documentation
For a complete breakdown of the calibration methodology, zero-dust baseline evaluation, and statistical analysis, please refer to the comprehensive academic report located in the `/Docs` folder.
