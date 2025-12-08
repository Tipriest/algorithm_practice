import numpy as np
import viser

def main():
    server = viser.ViserServer()
    # generate a spiral point cloud
    num_points = 400
    t = np.linspace(0, 20, num_points)
    spiral_positions = np.column_stack(
        [
            0.6*np.sin(t)*(1+t/5),
            0.6*np.cos(t)*(1+t/5),
            t/5
        ]
    )
    # Create colors based on height (z-coordniate)
    z_min = spiral_positions[:,2].min()
    z_max = spiral_positions[:,2].max()
    normalized_z = (spiral_positions[:,2]-z_min)/(z_max - z_min)
    
    # Color gradient from blue(bottom) to red(top)
    colors = np.zeros((num_points, 3), dtype=np.uint8)
    colors[:, 0] = (normalized_z*255).astype(np.uint8)# red channel
    colors[:, 2] = ((1-normalized_z)*255).astype(np.uint8)#blue channel
    
    # Add the point cloud to the scene
    server.scene.add_point_cloud(
        name = "/spiral_cloud",
        points=spiral_positions,
        colors=colors,
        point_size=0.05
    )
    
    
    # Add a second point cloud - random noise points
    num_noise_points = 5000
    noise_positions = np.random.normal(0, 1, (num_noise_points, 3))
    noise_colors = np.random.randint(0, 255, (num_noise_points, 3), dtype = np.uint8)
    
    noise_positions[:,0]+=5.0
    noise_positions[:,1]+=5.0
    server.scene.add_point_cloud(
        name = "/noise_cloud",
        points = noise_positions,
        colors= noise_colors,
        point_size=0.03
    )
    
    print("Point cloud visualization loaded!")
    print("- Spiral point cloud with height-based colors")
    print("- Random noise point cloud with random colors")
    print("Visit: http://localhost:8080")
    
    while True: 
        pass
    
if __name__ == "__main__":
    main()
    
    
    