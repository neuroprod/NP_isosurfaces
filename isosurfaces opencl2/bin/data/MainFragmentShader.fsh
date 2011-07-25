//
//
//  Created by Kris Temmerman on 29/11/10.
//  Copyright 2010 Neuro Productions. All rights reserved.
//



varying vec3 normal_var;
varying vec3 eyeVec;
varying vec3 lightDir;
varying vec3 lightDir2;

void main()
{
	vec3 N = normalize(normal_var);
	vec3 L = normalize(lightDir);
    vec3 L2 = normalize(lightDir2);
     vec3 E = normalize(-eyeVec);
	float lambertTerm2 = dot(N,E );
    
    vec3 col = vec3(1.0,0.9,0.7)*lambertTerm2 +vec3(1.0,1.0,1.0)*(1.0-lambertTerm2);
    
    
	float lambertTerm = dot(N,L);
	vec3 final_color =vec3(0.0,0.0,0.0);
    
	if(lambertTerm > 0.0)
	{
		final_color += col * lambertTerm;	
		
       
        vec3 R = reflect(-L, N);
        float p = max(dot(R, E), 0.0);
        
        vec3 R2 = reflect(-L2, N);
        float p2 = max(dot(R2, E), 0.0);
        
		float specular = p*p*p*p ;
		final_color += vec3(0.1,0.1,0.0)*specular;	
        
        float specular2 =p2*p2*p2*p2*p2*p2*p2*p2*p2 ;
		final_color += vec3(0.5,0.5,0.5)*specular2;	
	}
   // final_color += vec3(0.2,0.0,0.0);
    gl_FragColor =vec4(final_color,1.0);
    //gl_FragColor =vec4((normal_var.x+1.0)/2.0,(normal_var.y+1.0)/2.0,(normal_var.z+1.0)/2.0,1.0);
}

