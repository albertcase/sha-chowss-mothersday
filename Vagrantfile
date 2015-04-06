# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
    config.vm.box = "ubuntu12.04-20150208"
    config.vm.hostname = "ChowSSMSD"

    config.vm.network :forwarded_port, guest: 80, host: 9008
    config.vm.network :forwarded_port, guest: 3306, host: 33088

    config.vm.network :private_network, ip: "192.168.33.2"

    config.vm.synced_folder "./", "/vagrant", :nfs => true

    config.vm.provider :virtualbox do |vb|
        vb.customize ["modifyvm", :id, "--memory", "1024"]
        # show GUI of virtualbox
        #vb.gui = true
    end

    config.vm.provision :puppet do |puppet|
        puppet.module_path = "puppet/modules"
        puppet.manifests_path = "puppet/manifests"
        puppet.manifest_file  = "site.pp"
        # debug mode
        #puppet.options = "--verbose --debug"
    end
end
