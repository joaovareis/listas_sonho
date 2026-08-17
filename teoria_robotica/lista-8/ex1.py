import math
import numpy as np
import matplotlib.pyplot as plt

class meu_robo:
    def __init__(self, r, L, dt, int_pose):

        self.r = r
        self.L = L
        self.dt = dt
        self.int_pose = int_pose

    def calcular_pos(self, wL, wR, delta_t, metodo):

        v_k = (self.r / 2) * (wL + wR)
        w_k = (self.r / self.L) * (wR - wL)

        match metodo:

            case "EXATA":

                if w_k != 0:

                    R_k = v_k / w_k

                    ICC_x = self.int_pose[0] - R_k * math.sin(self.int_pose[2])
                    ICC_y = self.int_pose[1] + R_k * math.cos(self.int_pose[2])

                    mat_rot = np.array([
                        [math.cos(w_k*delta_t), -math.sin(w_k*delta_t), 0],
                        [math.sin(w_k*delta_t),  math.cos(w_k*delta_t), 0],
                        [0                    ,  0                    , 1]
                    ])

                    col_pos_icc = np.array([
                        [self.int_pose[0] - ICC_x],
                        [self.int_pose[1] - ICC_y],
                        [self.int_pose[2]        ]])

                    rev_pos_icc = np.array([
                        [ICC_x        ],
                        [ICC_y        ],
                        [w_k * delta_t]])

                    self.int_pose = (mat_rot @ col_pos_icc + rev_pos_icc).T.flatten()

                else: 

                    desl = v_k * delta_t

                    self.int_pose[0] += desl * math.cos(self.int_pose[2])
                    self.int_pose[1] += desl * math.sin(self.int_pose[2])

            case "EULER":

                n_passos = int(delta_t/self.dt)

                for i in range (n_passos):

                    self.int_pose[0] += v_k * self.dt * math.cos(self.int_pose[2])
                    self.int_pose[1] += v_k * self.dt * math.sin(self.int_pose[2])
                    self.int_pose[2] += w_k * self.dt

            case "PM":

                n_passos = int(delta_t/self.dt)
                
                for i in range (n_passos):

                    theta_min = self.int_pose[2] + ((self.dt / 2) * w_k)

                    self.int_pose[0] += v_k * self.dt * math.cos(theta_min)
                    self.int_pose[1] += v_k * self.dt * math.sin(theta_min)
                    self.int_pose[2] += w_k * self.dt

    def simular_trajetoria(self, comandos, metodo):
            
            trajetoria = [self.int_pose.copy()]
    
            for trecho in comandos:
                self.calcular_pos(**trecho, metodo=metodo)
                trajetoria.append(self.int_pose.copy())
    
            return np.array(trajetoria)

def main():

    comandos = [
        dict(wL=10.0, wR=10.0, delta_t=2.0),
        dict(wL=5.0,  wR=15.0, delta_t=1.6),
        dict(wL=10.0, wR=10.0, delta_t=2.0),
        dict(wL=15.0, wR=5.0,  delta_t=1.6),
    ]
    
    r, L, dt = 0.05, 0.3, 0.1
    pose_inicial = np.array([0., 0., 0.])
    
    robo_exata = meu_robo(r, L, dt, pose_inicial.copy())
    traj_exata = robo_exata.simular_trajetoria(comandos, "EXATA")
    print(f"Pose final (exata): ({robo_exata.int_pose[0]:.4f}, {robo_exata.int_pose[1]:.4f}, {robo_exata.int_pose[2]:.4f})")
    
    robo_euler = meu_robo(r, L, dt, pose_inicial.copy())
    traj_euler = robo_euler.simular_trajetoria(comandos, "EULER")
    print(f"Pose final (euler): ({robo_euler.int_pose[0]:.4f}, {robo_euler.int_pose[1]:.4f}, {robo_euler.int_pose[2]:.4f})")
    
    robo_pm = meu_robo(r, L, dt, pose_inicial.copy())
    traj_pm = robo_pm.simular_trajetoria(comandos, "PM")
    print(f"Pose final (ponto medio): ({robo_pm.int_pose[0]:.4f}, {robo_pm.int_pose[1]:.4f}, {robo_pm.int_pose[2]:.4f})")
    
    gt = np.genfromtxt("teoria_robotica/lista-8/ground_truth_diferencial.csv", delimiter=",", skip_header=1)
    gt_x = gt[:, 1]
    gt_y = gt[:, 2]
    
    plt.figure(figsize=(8, 8))
    
    plt.plot(gt_x, gt_y, color="gray", linewidth=3, label="Ground truth", alpha=0.2)
    plt.plot(traj_exata[:, 0], traj_exata[:, 1], linestyle="-",  label="Exata", alpha=0.5, color="red")
    plt.plot(traj_euler[:, 0], traj_euler[:, 1], linestyle="--", label="Euler")
    plt.plot(traj_pm[:, 0],    traj_pm[:, 1],    linestyle=":",  label="Ponto Médio", color="green")
    
    plt.xlabel("x [m]")
    plt.ylabel("y [m]")

    plt.xlim(-0.2, 1.6)
    plt.ylim(-0.2, 1.6)
    plt.legend()
    plt.axis("equal")
    plt.grid(True)
    plt.title("Comparação das trajetórias")
    plt.show()

if __name__ == "__main__":
    main()