

__kernel void update(__global float4 *positions, __global float4 *normals,__global float4 * particles ,const int numParticles  ) {
	int id = get_global_id(0);
  
	float4 n =(float4)(0.0,0.0,0.0,0.0);
	
	float w =0.0;
    float4 pos = positions[id];
    int j;
    for( j=0; j<numParticles; ++j) 
    {
          

          float4 ld = particles[j]-pos ;
           
          float pointWeight =ld.x*ld.x+ld.y*ld.y+ld.z*ld.z;              
         
         // n +=ld/(pow(pointWeight,2));
          w += 1.0/pointWeight;
        
        
    }

	
    //normals[id] =fast_normalize(n);
	normals[id].w = w;
}


