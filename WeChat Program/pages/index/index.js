const devicesId = "954642484" //onenet device ID
const api_key = "npVEwpLMOX5A1z=EhzvGqYLJz7I=" //onenet apikey
Page({
    data:{
        "name":"",  
        "number":"",
        "time":"",
        receive:[]  //接收到的onenet数据
    },

    //上传信息的函数
    formsubmit:function(e){
        this.setData({
            name:e.detail.value.name,
            number:e.detail.value.number,
            time:e.detail.value.time
        })//首先将传入的药品信息赋给data中的变量，方便后续调用
        //发送http POST请求，将数据上传至onenet云
        wx.request({
            url: `http://api.heclouds.com/devices/${devicesId}/datapoints`,
            header: {
              'content-type': 'application/json',
              'api-key': api_key
            },
            data:{
                "datastreams": [{
                    "id": this.data.name+"_"+this.data.time,
                    "datapoints": [
                        {
                            "value": this.data.number
                        }
                    ]
                }  
            ]
            },
            method:'POST',
            success:(res)=>{
                console.log(res);
            },
            fail:(err)=>{
                console.log(err);
            }
        })
    },

    formrest:function(){

    },

})